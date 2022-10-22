# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 22:25:04 by marvin            #+#    #+#              #
#    Updated: 2022/10/22 17:21:03 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
OPENGL		=	 ./minilibx ./minilibx/libmlx.a ./libft/libft.a -framework OpenGL -framework AppKit
RM			=	rm -f

SRCS				=	so_long.c 
OBJS				=	$(SRCS:%.c=%.o)


 

all: $(NAME)		

$(NAME): $(OBJS)
	make -C ./libft
	make -C ./minilibx
	$(CC) -o $(NAME) $(SRCS) -I $(OPENGL) $(CFLAGS)
	@echo "So_Long  Done !"
clean:
					make clean -C ./libft
					make clean -C ./minilibx
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean $(NAME)

					
.PHONY:	all clean fclean re

