# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 22:25:04 by marvin            #+#    #+#              #
#    Updated: 2022/09/16 15:49:01 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I.
OPENGL		=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f
MAKE		=	make

SRCS				=	so_long.c 
OBJS				=	$(SRCS:.c=.o)


 

all:				
					$(MAKE) -C libft/
						@echo "libft Done !"
					$(NAME)

$(NAME):			$(OBJS)
						$(CC) $(CFLAG) $(OPENGL) -o $(NAME)
						@echo "So_Long  Done !"
clean:
					$(MAKE) clean -C libft/	
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean $(NAME)

					
.PHONY:	all clean fclean re

