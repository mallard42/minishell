# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mallard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/21 17:28:15 by mallard           #+#    #+#              #
#    Updated: 2017/09/02 17:30:30 by mallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE = \033[38;5;129m
GREEN = \033[38;5;82m
RED = \033[38;5;208m
DEFAULT = \x1b[0m

NAME = minishell

LIBFT = ./libft/libft.a

SRC = main.c command.c tab.c error.c access.c ft_split.c ft_echo.c ft_cd.c \
	  path.c env.c

SRCS = $(addprefix src/, $(SRC));

OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wextra -Wall

all : $(NAME)

norme :
		@echo "$(RED)     .-') _            _  .-') _   .-')      ('-."
		@echo "    ( OO ) )          ( \( -O ( '.( OO )_  _(  OO)"
		@echo ",--./ ,--,' .-'),-----.,------.,--.   ,--.(,------."
		@echo "|   \ |  |\( OO'  .-.  |   /\`. |   \`.'   | |  .---'"
		@echo "|    \|  | /   |  | |  |  /  | |         | |  |"
		@echo "|  .     |/\_) |  |\|  |  |_.' |  |'.'|  |(|  '--."
		@echo "|  |\    |   \ |  | |  |  .  '.|  |   |  | |  .--'"
		@echo "|  | \   |    \`'  '-'  |  |\  \|  |   |  | |  \`---."
		@echo "\`--'  \`--'      \`-----'\`--' '--\`--'   \`--' \`------'"
		@echo "$(DEFAULT)"
		@norminette ./include libft/include
		@norminette $(SRCS)
		@norminette libft/src

$(LIBFT) :
		@$(MAKE) -C ./libft

$(NAME) : $(LIBFT)
		@echo "$(PURPLE)build $(NAME)$(DEFAULT)"
		@gcc -c $(SRCS)
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

.PHONY : re all norme clean fclean
