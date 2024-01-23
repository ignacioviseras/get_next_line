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
	// free(str);
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

static char *rest(char *buffer)
{
	char *sentence;

	sentence = ft_strchr(buffer, '\n');
	return (sentence+1);
}

static char	*read_file(int fd)
{
	char *buffer;
	char *aux;
	int status;
	static char *txt;

	if (!txt)
		txt = "";
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	status = read(fd, buffer, BUFFER_SIZE);
	while (status > 0)
	{
		if (status < 0)//controls de read en whiles
			return (free(buffer), NULL);
		txt = ft_strjoin(txt, buffer);
		if (ft_strchr(txt, '\n'))
		{
			aux = extract(txt);
			// free(txt)
			txt = rest(txt);
			break;
		}
		status = read(fd, buffer, BUFFER_SIZE);
	}
	return (aux);
}

char	*get_next_line(int fd)
{
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	line = read_file(fd);
	
	return (line);
}

int	main ()
{
	char file[] = "./prueba.txt";
	int a;

	a = open(file, O_RDONLY);
	printf("%s", get_next_line(a));
	// printf("%s", get_next_line(a));
	// printf("%s", get_next_line(a));
	// printf("%s", get_next_line(a));
	close(a);
	return (0);
}

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
//         free(str);
//         i++;
//     }
//     printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
//     return (0);
// }