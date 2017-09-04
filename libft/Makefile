# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mallard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 12:22:19 by mallard           #+#    #+#              #
#    Updated: 2017/06/22 14:41:48 by mallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYAN = \033[38;5;30m
GREEN = \033[38;5;64m
DEFAULT = \x1b[0m

NAME = libft.a

FLAGS = -Werror -Wall -Wextra

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	  ft_strcat.c ft_strncat.c ft_strchr.c ft_strnstr.c ft_strcmp.c \
	  ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strncpy.c \
	  ft_strrchr.c ft_strstr.c ft_strlcat.c ft_putchar.c ft_putstr.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_strclr.c ft_putendl.c \
	  ft_putendl_fd.c ft_strequ.c ft_strnequ.c ft_putnbr.c ft_putnbr_fd.c \
	  ft_memalloc.c ft_strnew.c ft_memdel.c ft_strdel.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c \
	  ft_strtrim.c ft_itoa.c ft_abs.c ft_intlen.c ft_strsplit.c ft_lstnew.c \
	  ft_lstdelone.c ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
	  ft_lstaddend.c ft_swap.c ft_foreach.c ft_lstsize.c ft_strjoin_f.c \
	  ft_lstresearch.c ft_strcount.c get_next_line.c

OBJ = $(SRC:.c=.o)

SRCS = $(addprefix src/, $(SRC));

all: $(NAME)

$(NAME):
	@echo "$(CYAN)build libft$(DEFAULT)"
	@gcc -c -I $(FLAGS) $(SRCS)
	@ar rc $(NAME) $(OBJ)

clean:
	@echo "$(GREEN)clean libft's object$(DEFAULT)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(GREEN)clean $(NAME)$(DEFAULT)"
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
