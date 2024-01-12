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
	char *all_text;//lo q queda por leer
	int status;//pa sabéh si ce pue lee
	char *sentence;
	int len_word;

	len_word = 0;
	status = read(fd, all_text, BUFFER_SIZE);
	if (!ft_strchr(all_text, '\n'))
		len_word = ft_strlen(all_text);
	else
		len_word = ft_strchr(all_text, '\n') - all_text;
	sentence = ft_substr(all_text, 0, len_word);
	printf("\ncadena %s", sentence);
	close(fd);
	return (sentence);
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
	printf("\nsentence %s", text);
	return (NULL);
}


int	main ()
{
	char *file = "./prueba.txt";
	get_next_line(open(file, O_RDONLY));
	return (0);
}
