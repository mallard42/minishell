# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mallard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/21 17:28:15 by mallard           #+#    #+#              #
#    Updated: 2017/05/21 18:18:54 by mallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE = \033[38;5;129m
GREEN = \033[38;5;82m
RED = \033[38;5;208m
DEFAULT = \x1b[0m

TOOLS = \xU+1F6E0
TRASH = \xU+1F5D1

NAME = minishell

P = ./src/

LIBFT = ./libft/libft.a

SRC = $(P)main.c $(P)command.c $(P)tab.c

OBJ = main.o command.o tab.o

FLAGS = -Werror -Wextra -Wall -g

all : $(NAME)

norme :
		@echo "$(RED)norme sources et includes$(DEFAULT)"
		@norminette ./include libft/include
		@norminette $(SRC) libft/src

$(LIBFT) :
		@$(MAKE) -C ./libft

$(NAME) : $(LIBFT)
		@echo "$(PURPLE)build $(NAME)$(DEFAULT)"
		@gcc -c $(SRC)
		@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean :
		@$(MAKE) clean -C ./libft
		@rm -f $(OBJ)
		@echo "$(GREEN)clean $(NAME)'s object$(DEFAULT)"

fclean : clean
		@echo "$(GREEN)clean $(NAME)$(DEFAULT)"
		@echo "$(GREEN)clean libft.a $(DEFAULT)"
		@$(MAKE) fclean -C ./libft
		@rm -f $(NAME)

re : fclean all

.PHONY : re all norme $(NAME) clean fclean $(LIBFT)
