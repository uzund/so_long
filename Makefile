# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 22:25:04 by marvin            #+#    #+#              #
#    Updated: 2022/11/13 23:06:15 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

KIRMIZI		= \033[0;31m
YESIL		= \033[0;32m
MAVI		= \033[0;34m
SIFIRLA		= \033[0m
SONLANDIR	= \e[0m

SRCS		= 	srcs/main.c \
				srcs/building_map.c \
				srcs/check_map.c \
				srcs/so_long.c \
				srcs/move.c \
				srcs/utils.c \
				srcs/check_map_way.c \
				srcs/check_map_way2.c
NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g
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
	@printf	"\033[2K\r${KIRMIZI}[DERLENİYOR!]${SIFIRLA} '$<' $(SONLANDIR)"

$(NAME): $(OBJECTS_PREFIXED) makeyap
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CFLAGS) ./ft_printf/libftprintf.a ./libft/libft.a ./minilibx/libmlx.a ${MXFLAGS}
	@printf "\033[2K\r${YESIL}[KURULUM TAMAMLANDI]${MAVI} -- >${KIRMIZI} $(NAME) ${MAVI}< --${SIFIRLA}$(SONLANDIR)\a\n"
	@printf "\033[2K\r${KIRMIZI}Çalıştırmak için: ${MAVI} ./so_long <*.ber> ${YESIL} // örnek: ./so_long map.ber)${SIFIRLA}$(SONLANDIR)\n"

all: $(NAME)	

makeyap:
	@make -C ./libft
	@make -C ./minilibx
	@make -C ./ft_printf
 
clean:
	@make clean -C ./libft
	@make clean -C ./minilibx
#	@make clean -C ./ft_printf
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${YESIL}[CLEAN]${KIRMIZI}[TAMAMLANDI]${SIFIRLA}$(SONLANDIR)\a\n"

fclean: clean
	@make fclean -C ./libft
#	@make fclean -C ./minilibx
	@make fclean -C ./ft_printf
	@rm -f $(NAME)
	@printf "\033[2K\r${YESIL}[FCLEAN]${KIRMIZI}[TAMAMLANDI]${SIFIRLA}$(SONLANDIR)\a\n"
	
re:	fclean all
				
.PHONY:	all clean fclean re
