# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 22:25:04 by marvin            #+#    #+#              #
#    Updated: 2022/11/16 09:56:55 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[0;31m
GREEN		= \033[0;32m
BLUE		= \033[0;34m
RESET		= \033[0m
END			= \e[0m

SRCS		= 	srcs/main.c \
				srcs/building_map.c \
				srcs/check_map.c \
				srcs/so_long.c \
				srcs/move.c \
				srcs/utils.c \
				srcs/utils2.c \
				srcs/check_map_way.c \
				srcs/check_map_way2.c
NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -std=c11 -g
MXFLAGS		=	-framework OpenGL -framework AppKit
RM			=	rm -f
OBJS_DIR	= 	objs/
PROJECT_H	= 	srcs/so_long.h
OBJS		=	$(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf	"\033[2K\r${RED}[DERLENİYOR! / COMPILING!]${RESET} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED) makerun
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CFLAGS) ./ft_printf/libftprintf.a ./libft/libft.a ./minilibx/libmlx.a ${MXFLAGS}
	@printf "\033[2K\r${GREEN}[KURULUM TAMAMLANDI]${BLUE} -- >${RED} $(NAME) ${BLUE}< --${RESET}$(END)\a\n"
	@printf "\033[2K\r${RED}Çalıştırmak için: ${BLUE} ./so_long <*.ber> ${GREEN} // örnek: ./so_long map.ber)${RESET}$(END)\n"
	@printf "\033[2K\r${GREEN}[INSTALLATION COMPLETED]${BLUE} -- >${RED} $(NAME) ${BLUE}< --${RESET}$(END)\a\n"
	@printf "\033[2K\r${RED}To make it work: ${BLUE} ./so_long <*.ber> ${GREEN} // sample: ./so_long map.ber)${RESET}$(END)\n"

all: $(NAME)	

makerun:
	@make -C ./libft
	@make -C ./minilibx
	@make -C ./ft_printf
 
clean:
	@make clean -C ./libft
	@make clean -C ./minilibx
	@make clean -C ./ft_printf
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GREEN}[CLEAN]${RED}[TAMAMLANDI / COMPLETED]${RESET}$(END)\a\n"

fclean: clean
	@make fclean -C ./libft
#	@make fclean -C ./minilibx
	@make fclean -C ./ft_printf
	@rm -f $(NAME)
	@printf "\033[2K\r${GREEN}[FCLEAN]${RED}[TAMAMLANDI / COMPLETED]${RESET}$(END)\a\n"
	
re:	fclean all
				
.PHONY:	all clean fclean re
