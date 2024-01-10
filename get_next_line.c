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
// 	text = ft_strchr(buf, '\n');
// 	ft_strdup(text);
// 	return (ft_strlen(text));
// }

static char	*read_file(int fd, char buf, char *text)
{
	char *leter;
	int status;

	status = read(fd, buf, BUFFER_SIZE);
	while (status > 0)
	{
		leter = ft_strchr(buf, '\n');
		text = leter;
		status = read(fd, buf, BUFFER_SIZE);
	}
	if (status == 0)
		leter = ft_strchr(buf, '\0');
	return (leter);
	// break;

	// buf = "hola que tal\n aqui estamos\0"
	// buf = "a"
	// if (buf[index] == \n || \0)
	// {
	// }
	// while (\n || \0)
	// 	index++;

	ft_strchr(buf, '\0');
	printf("GNL");
	close(fd);
	return (leter);
}

char	*get_next_line(int fd)
{
	char *line;
	char *buf;
	static char *text;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// buf = '\0';
	if (!buf)
		return (0);
	line = read_file(fd, buf, text);
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