/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:52:17 by igvisera          #+#    #+#             */
/*   Updated: 2023/12/21 20:15:29 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, const char *s2) 
{ 
	char	*str; 
	size_t	i; 
	size_t	j; 
 
	i = 0; 
	j = 0; 
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)); 
	if (str == NULL) 
		return (NULL); 
	while (s1[i] != '\0') 
	{ 
		str[i] = s1[i]; 
		i++; 
	} 
	while (s2[j] != '\0') 
	{ 
		str[i] = s2[j]; 
		j++; 
		i++; 
	} 
	str[i] = '\0'; 
	free(s1);
	return (str); 
} 
 
static char *extract(char *buffer) 
{ 
	char *sentence; 
	int len_sentence; 
	int len_all; 
	 
	len_all = 0; 
	len_sentence = 0; 
 
	len_all = ft_strlen(buffer); 
	len_sentence = ft_strlen(ft_strchr(buffer, '\n')); 
	sentence = ft_substr(buffer, 0, len_all - len_sentence + 1); 
	return (sentence); 
} 
 
static char *line(char **txt) 
{ 
	char *aux; 
	char *finder; 
 
	// printf("line %p\n", *txt);
	// if (*txt == "") 
	// { 
	// 	free(*txt); 
	// 	return (NULL); 
	// } 
	finder = ft_strchr(*txt, '\n'); 
	if (finder) 
	{
		aux = extract(*txt); 
		*txt = finder + 1;
		return (aux); 
	} 
	else 
	{
		// printf("qwe %p\n", *txt);
		aux = ft_strdup(*txt);
		//free(*txt);
		//printf("zxc %p\n", *txt);
		*txt = NULL;
		return (aux);
	}
	return (aux); 
} 

static char	*read_file(int fd) 
{ 
	char buffer[BUFFER_SIZE + 1]; 
	int status; 
	static char *txt; 
	char *aux; 
 
	status = read(fd, buffer, BUFFER_SIZE); 
	if (status < 0) //controls de read en whiles 
		return (NULL); 
	while (status > 0) 
	{ 
		if (!txt)
		{
			aux = txt; 
			txt = ft_strdup(buffer);
			free(aux); 
		}
		else 
		{ 
			aux = txt; 
			txt = ft_strjoin(txt, buffer); 
			free(aux); 
		} 
		// printf("txt %p\n", txt);
		if (ft_strchr(txt, '\n') || !(ft_strchr(txt, '\0'))) 
			break;
		status = read(fd, buffer, BUFFER_SIZE);
		if (status < 0)//controls de read en whiles
		{
			// free(txt);
			txt = NULL;
			return (txt);
		}
	}
	return (line(&txt));
} 

char	*get_next_line(int fd)
{ 
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	line = read_file(fd);
	
	return (line);
} 

// void leaks() {
// 	system("leaks a.out");
// }

// int main(void)
// {
// 	//atexit(leaks);
//     int     fd; 
//     char    *str; 
//     int     i; 
 
//     i = 0; 
//     fd = open("prueba.txt", O_RDONLY);
//     // while ((i <= 6)) 
//     // { 
//         str = get_next_line(fd);
// 		free(str);
// 		str = get_next_line(fd);
// 		// free(str);
// 		// str = get_next_line(fd);
// 		// free(str);
//         // printf("line %i=>%s\n", i + 1, str);
// 	// 	fflush(NULL);
//     //     free(str);
//     //     i++; 
//     // } 
//     printf("BUFFER_SIZE = %d\n", BUFFER_SIZE); 
//     return (0); 
// }


// int	main () 
// { 
// 	printf("%s", get_next_line(1)); 
// 	return (0); 
 
// } 
 
// int	main () 
// { 
// 	char file[] = "./prueba.txt"; 
// 	int a; 
// 	char *str; 
 
// 	a = open(file, O_RDONLY); 
	 
// 	while((str = get_next_line(a)) != NULL) 
// 	{ 
// 		printf("%s\n", str); 
// 		free(str); 
// 	} 
// 	free(str); 
// 	//printf("%s\n", get_next_line(a)); 
// 	// printf("%s", get_next_line(a)); 
// 	// printf("%s", get_next_line(a)); 
// 	// printf("%s", get_next_line(a)); 
// 	close(a); 
// 	return (0); 
// } 
 
// int main() 
// { 
// 	char *q; 
 
// 	q = "hola como estamos\nqweasdzxcasdqweqwe\n1321321321321\niasomad"; 
// 	printf("%s", extract(q)); 
// 	printf("%s", rest(q)); 
 
// 	return (0); 
// } 