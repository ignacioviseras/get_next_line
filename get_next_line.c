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


static char *have_n(char *buffer)
{
	char *sentence;//lo extraido
	int len_sentence;
	len_sentence = 0;

	len_sentence = ft_strlen(ft_strchr(buffer, '\n'));
	sentence = ft_strdup(buffer + len_sentence);
	return (sentence);
}

static char *end_line(char *buffer)
{
	char *sentence;
	int len_sentence;
	len_sentence = 0;

	len_sentence = ft_strlen(ft_strchr(buffer, '\n'));
	sentence = ft_substr(buffer, 0, len_sentence);
	return (sentence);
}

static char	*read_file(int fd)
{
	char *buffer;//lo q queda por leer
	int status;//pa sabéh si ce pue leer
	static char *txt;//guardado
	char *aux;
	char *sentence;//lo extraido
	char *start;

	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!txt)
		txt = "";
	status = read(fd, buffer, BUFFER_SIZE);
	while (status > 0)
	{
		if (status < 0)//controls de read en whiles
			return (free(buffer), NULL);
		buffer[status] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			sentence = have_n(buffer);
			start = end_line(buffer);
			aux = ft_strjoin(txt, start);
			txt = ft_strdup(sentence);
			return (aux);
		}
		else
		{
			if (!txt)
				txt = ft_strdup(buffer);
			else
				txt = ft_strjoin(txt, buffer);
		}
		status = read(fd, buffer, BUFFER_SIZE);
	}
	return (txt);
}

char	*get_next_line(int fd)
{
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	line = read_file(fd);
	printf("%s", line);
	
	return (NULL);
}

int	main ()
{
	char file[] = "./prueba.txt";
	int a;

	a = open(file, O_RDONLY);
	get_next_line(a);
	get_next_line(a);
	// get_next_line(a);
	close(a);
	return (0);
}