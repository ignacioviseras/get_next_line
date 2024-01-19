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

static char	*read_file(int fd)
{
	char *all_text;//lo q queda por leer
	int status;//pa sabéh si ce pue leer
	static char *txt;//guardado
	char *sentence;//lo recibido
	char *aux;
	int len_sentence;

	all_text = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!txt)
		txt = "";
	aux = calloc(BUFFER_SIZE + 1, sizeof(char));
	len_sentence = 0;
	status = 1; //read(fd, all_text, BUFFER_SIZE);
	while (status > 0)
	{
		status = read(fd, all_text, BUFFER_SIZE);
		all_text[status] = '\0';
		//ctr del read
		if (status < 0)
			return (free(all_text), NULL);
		if (ft_strchr(all_text, '\n'))// "asdasd\nc"
		{
			// ft_strlcpy(aux, all_text, ft_strlen(all_text));
			len_sentence = ft_strlen(ft_strchr(all_text, '\n'));
			sentence = ft_substr(all_text, 0, len_sentence);//lo que pintaria la cadena
			txt = ft_strjoin(txt, sentence);
		}
		else
		{
			txt = ft_strjoin(txt, all_text);
		}
	}
	ft_strlcpy(aux, txt, ft_strlen(txt));
	free(txt);
	ft_strlcpy(txt, all_text, ft_strlen(all_text));
	// aux = txt;
	// txt = aux;
	return (aux);
}

char	*get_next_line(int fd)
{
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	line = read_file(fd);
	printf("\nCadena %s", line);
	
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
	get_next_line(a);
	close(a);
	return (0);
}





/*

asdasdasd\nqweqweqweqwe
aux = asdasdasd\nqweqweqweqwe

static txt = asdasdasd


\n\n\n\n\nasdasdasdasdasdasd\n\n\n\n\n

*/