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

char	*ft_strjoin(char const *s1, const char *s2)
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
	//free(&s1);
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
		aux = *txt;
		*txt = NULL;
		return (aux);
	}
	return (aux);
}

// static char	**free_all(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	return (free(str), NULL);
// }

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
			txt = ft_strdup(buffer);
		else
		{
			aux = txt;
			txt = ft_strjoin(txt, buffer);
			free(aux);
		}
		if (ft_strchr(txt, '\n') || !(ft_strchr(txt, '\0')))
			break;
		status = read(fd, buffer, BUFFER_SIZE);
		if (status < 0)//controls de read en whiles
			return (NULL);
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

// int main(void)
// {
//     int     fd;
//     char    *str;
//     int     i;

//     i = 0;
//     fd = open("prueba.txt", O_RDONLY);
//     while ((i <= 6))
//     {
//         str = get_next_line(fd);
//         printf("line %i=>%s\n", i + 1, str);
//         //free(str);
//         i++;
//     }
//     printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
//     return (0);
// }