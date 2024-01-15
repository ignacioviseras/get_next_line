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
static void free_all(char *str)
{
	free(str);
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
	// return (str);
	return (str); //no va el free de s1
}

// size_t	have_n(char *dst, char *src)
// {
// 	size_t	src_lenght;
// 	size_t	index;

// 	index = 0;
// 	src_lenght = ft_strlen(src);
// 	while (src[index] != '\0' && src[index] != '\n')
// 	{
// 		dst[index] = src[index];
// 		index++;
// 	}
// 	dst[index] = '\0';
// 	return (src_lenght);
// }

static char	*read_file(int fd)
{
	char *all_text;//lo q queda por leer
	int status;//pa sabéh si ce pue leer
	char *sentence;//lo recibido
	static char *txt;//guardado
	int len_sentence;
	
	// char *p;

	all_text = calloc(BUFFER_SIZE + 1, sizeof(char));
	// *all_text = '\0';
	if (!txt)
		txt = "";
	len_sentence = 0;
	status = read(fd, all_text, BUFFER_SIZE);
	while (status > 0)
	{
		if (!ft_strchr(all_text, '\n')){
			// printf("\n all %s", txt);
			len_sentence = ft_strchr(all_text, '\n') - all_text;
			sentence = ft_substr(all_text, 0, len_sentence);//lo que pintaria la cadena
			txt = ft_strjoin(txt, sentence);
			status = read(fd, all_text, BUFFER_SIZE);
		
		}
		else // "\nco "  "tal\nco"
		{
			printf("\n all %s", all_text);
			len_sentence = ft_strchr(all_text, '\n') - all_text;
			sentence = ft_substr(all_text, 0, len_sentence);//lo que pintaria la cadena
			txt = ft_strjoin(txt, all_text + len_sentence);
			// return (all_text);
			
			break;
		}
		// printf("\ntxt %s", txt);
	}
	return (txt);
}

char	*get_next_line(int fd)
{
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	// printf("l1 %s", text);
	line = read_file(fd);
	
	printf("\nline %s", line);
	return (NULL);
}

int	main ()
{

	// printf("Cadena %s", have_n("qwe"));
	char file[] = "./prueba.txt";
	int a;

	a = open(file, O_RDONLY);
	get_next_line(a);
	get_next_line(a);
	close(a);
	return (0);
}





/*

hola\n
que tal





*/