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

//clean all the mpomry
static void	**free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	return (free(str), NULL);
}

// static int *value_line(char *buf)
// {
// 	printf("VALUE LINE");
// 	char *text;
// 	text = ft_strrchr(buf, '\n');
// 	ft_strdup(text);
// 	return (ft_strlen(text));
// }


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
	return (str);
	// return (free(s1), str); no va el free de s1
}

static char	*read_file(int fd, char *text)
{
	char *letter;//lo q queda por leer
	char *buf;//no esta debaj para no tener leaks
	int status;//pa saber si se puede leer
	char *qwe;

	// status = 1;
	// buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// if (!buf)
	// 	free(buf);
	status = read(fd, letter, BUFFER_SIZE);
	printf("\nl4 %d", status);
	// if (status < 0) //no funciona pq status es el ncaractrs leido
	// 	return (NULL);

	// buf[BUFFER_SIZE] = '\0';
	qwe = ft_strchr(letter, 'a');
	ft_strjoin(text, qwe);
	printf("\nl2 %s", qwe);
	
	// while (!text || 
	// 	(status > 0 && ft_strrchr(text, '\n') == NULL))
	// {
	// 	status = read(fd, buf, BUFFER_SIZE);
	// 	// if (status < 0)
	// 	// 	return (free)
	// 	buf = letter;
	// 	text = ft_strjoin(text, buf);
	// 	// printf("pr1: %s", letter);
	// }
	// if (status == 0)
	// 	letter = ft_strrchr(buf, '\0');
	// printf("pr2: %s", letter);
	// return (text);

	// break;
	// buf = "hola que tal\n aqui estamos\0"
	// buf = "a"
	// if (buf[index] == \n || \0)
	// {
	// }
	// while (\n || \0)
	// 	index++;

	// ft_strrchr(buf, '\0');
	printf("\nGNL");
	close(fd);
	return (qwe);
}

char	*get_next_line(int fd)
{
	char *line;
	static char *text;

	text = "";
	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	printf("l1 %s", text);
	text = read_file(fd, text);
	printf("QWE %s", text);
	// text += ft_strlen(line);
	return (NULL);
}

// char buf[BUFFER_SIZE+1];
// buf[BUFFER_SIZE] = '\0';
// buf = "hola que tal\naqui estamos"
// while (ft_strlen(buf) > 0)
// {
// 	size_text = value_line(buf);
// 	buf += ft_strlen(buf) + size_text;
// }
// printf("%s", filter_text);

int	main ()
{
	char *file = "./prueba.txt";
	get_next_line(open(file, O_RDONLY));

	return (0);
}