/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:48:38 by igvisera          #+#    #+#             */
/*   Updated: 2024/01/30 19:48:38 by igvisera         ###   ########.fr       */
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
	while (s1[i] != '\0' || !*s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' || !*s2)
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*extract(char *buffer)
{
	char	*sentence;
	int		len_sentence;
	int		len_all;

	if (!buffer || !*buffer)
		return (NULL);
	len_all = 0;
	len_sentence = 0;
	len_all = ft_strlen(buffer);
	len_sentence = ft_strlen(ft_strchr(buffer, '\n'));
	sentence = ft_substr(buffer, 0, len_all - len_sentence + 1);
	return (sentence);
}

static char	*line(char **txt)
{
	char	*aux;
	char	*finder;
	char	*t;

	if (!*txt)
		return (NULL);
	finder = ft_strchr(*txt, '\n');
	if (finder)
	{
		aux = extract(*txt);
		t = *txt;
		*txt = ft_strdup(finder + 1);
		free(t);
		return (aux);
	}
	else
	{
		aux = ft_strdup(*txt);
		free(*txt);
		*txt = NULL;
		return (aux);
	}
	return (aux);
}

static char	*read_file(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	int			status;
	static char	*txt;
	char		*aux;

	status = read(fd, buffer, BUFFER_SIZE);
	while (status > 0)
	{
		buffer[status] = '\0';
		if (!txt || !*txt)
			txt = ft_strdup(buffer);
		else
		{
			aux = txt;
			txt = ft_strjoin(txt, buffer);
			free(aux);
		}
		if (ft_strchr(txt, '\n') || !(ft_strchr(txt, '\0')))
			break ;
		status = read(fd, buffer, BUFFER_SIZE);
	}
	if (status < 0)
		return (free(txt), txt = NULL, txt);
	return (line(&txt));
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_file(fd);
	return (line);
}

// int	main (void)
// {
// 	char file[] = "./prueba.txt";
// 	int a;
// 	char *str;

// 	a = open(file, O_RDONLY);

// 	if (BUFFER_SIZE > 100) {
// 		char *temp;
// 		do {
// 			temp = get_next_line(a);

// 			free(temp);
// 		} while (temp != NULL);
// 	}

// 	close(a);
// 	a = open(file, O_RDONLY);

// 	while((str = get_next_line(a)) != NULL)
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	free(str);
// 	// printf("%s\n", get_next_line(a));
// 	// printf("%s", get_next_line(a));
// 	close(a);
// 	system("leaks a.out");
// 	return (0);
// }

// int main() {
// 	char *asd = NULL;
// 	printf("asd->'%s'", extract(asd));
// 	// extract(asd);
// 	return (0);
// }