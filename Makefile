# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 22:25:04 by marvin            #+#    #+#              #
#    Updated: 2022/10/27 01:14:01 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRCS		= 	srcs/main.c \
				srcs/build_map.c \
				srcs/check_map.c \
				srcs/pokemon.c \
				srcs/movements.c \
				srcs/utils.c
NAME		=	pokemon
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g
MXFLAGS		=	-framework OpenGL -framework AppKit
RM			=	rm -f
OBJS_DIR	= 	objs/
PROJECT_H	= 	srcs/pokemon.h
OBJS		=	$(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf	"\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED) makeyap
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CFLAGS) ./libft/libft.a ./minilibx/libmlx.a ${MXFLAGS}
	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"

all: $(NAME)	

makeyap:
	@make -C ./libft
	@make -C ./minilibx
 
clean:
	@make clean -C ./libft
	@make clean -C ./minilibx
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GRN}[CLEAN]${RST} done$(END)"

fclean: clean
	@make fclean -C ./libft
#	@make fclean -C ./minilibx
	@rm -f $(NAME)
	@printf "\033[2K\r${GRN}[FCLEAN]${RST} done$(END)"
	
re:	fclean all
				
.PHONY:	all clean fclean re
