# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 11:01:24 by egomez-a          #+#    #+#              #
#    Updated: 2021/10/23 19:53:27 by egomez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap
LIBFT		= 	libft.a
LIBFT_DIR	=	libft/
SRCS_DIR	=	sources/
OBJ_DIR		= 	obj/
SRCS 		=	push_swap.c
NOW			=	$(shell date +"%d-%m-%y %H:%M")

OBJS 		= 	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CFLAGS 		= 	-Wall -Wextra -Werror
DEBUGGING	= 	-g
LFLAGS		= 	-I includes/
CC 			= 	gcc
RM 			= 	rm -rf
NORM		= 	/usr/bin/norminette

NONE		=	'\033[0m'
GREEN		=	'\033[32m'
YELLOW		=	'\033[33m'
GRAY		=	'\033[2;37m'
CURSIVE		=	'\033[3m'

all: $(NAME)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@

$(NAME) : $(OBJS)
	@echo $(GRAY)"==== Compilation of Libft Library==== "$(NONE)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) $(LIBFT_DIR)$(LIBFT) -o $(NAME) $(OBJS)
	@echo $(GREEN)"=============== DONE ================"$(NONE)

clean:
		@echo "========== CLEAN =========="
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)
		make -C $(LIBFT_DIR) clean
		@echo "=========== DONE ==========="
		
fclean: clean
		@echo "========== FCLEAN =========="
		$(RM) $(NAME)
		make -C $(LIBFT_DIR) fclean
		@echo "=========== DONE ==========="

re: fclean all

git: fclean
	@echo "===== PUSHING to GITHUB ===="
	git add .
	git commit -m "Push_Swap - $(NOW)"
	git push origin master

norm: 
		$(NORM) $(SRC);

.PHONY: all, clean, fclean, re