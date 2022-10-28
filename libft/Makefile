# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 22:25:04 by marvin            #+#    #+#              #
#    Updated: 2022/10/28 12:47:59 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

SRCS	=	ft_isalnum.c \
			ft_isprint.c \
			ft_memcmp.c \
			ft_putchar_fd.c \
			ft_split.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_substr.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_itoa.c \
			ft_memcpy.c \
			ft_putendl_fd.c \
			ft_strchr.c \
			ft_strlcpy.c \
			ft_strnstr.c \
			ft_tolower.c \
			ft_bzero.c \
			ft_isascii.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_putnbr_fd.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strrchr.c \
			ft_toupper.c \
			ft_calloc.c \
			ft_isdigit.c \
			ft_memchr.c \
			ft_memset.c \
			ft_putstr_fd.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strmapi.c \
			ft_strtrim.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			get_next_line.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_nbrlen.c \
			ft_putnbr.c \
			ft_putnbrx.c \
			ft_putnbru.c \
			ft_putp.c
						
OBJS				=	$(SRCS:.c=.o)

all:				$(NAME)

$(NAME):			$(OBJS)
					ar rcs $(NAME) $(OBJS)
					@echo "Libft Done !"
clean:	
					$(RM) $(OBJS) $(BONUS_OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean $(NAME)
										
.PHONY:	all clean fclean re

