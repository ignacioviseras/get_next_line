# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 20:06:22 by igvisera          #+#    #+#              #
#    Updated: 2023/12/21 20:13:55 by igvisera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libft.a
OBJS	=	${SRCS:.c=.o}
CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=xx

SRCS	=	get_next_line_utils.c \
			get_next_line.c	\


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re