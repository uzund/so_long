# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 19:51:47 by duzun             #+#    #+#              #
#    Updated: 2022/10/28 13:00:50 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CFLAGS		=	-Wall -Wextra -Werror -I.
CC			=	gcc
RM			=	rm -f

SRCS			=	ft_printf.c 
					 
OBJS			= $(SRCS:.c=.o)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)
			
all:			$(CC) $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
