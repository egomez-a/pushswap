# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 11:01:24 by egomez-a          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2021/11/02 19:03:43 by egomez-a         ###   ########.fr        #
=======
#    Updated: 2021/11/02 19:03:26 by egomez-a         ###   ########.fr        #
>>>>>>> 549bbef3a44d3d4ca6b7fb6fe58eeadb01defac1
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap
LIBFT		= 	libft.a
LIBFT_DIR	=	libft/
SRCS_DIR	=	sources/
OBJ_DIR		= 	obj/

SRCS 		=	push_swap.c \
				push_stack.c \
				switch_stack.c \
				rotate_stack.c \
				reverserotate_stack.c \
				printstacks.c \
				orderbig.c \
				orderlow.c \
				check.c \
				insertion_sort.c \
				find_array_elements.c \
				ft_squareroot.c \
				chunks.c \

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
RED			=	'\033[0;31m'
ORANGE		=	'\033[0;33m'
BLUE		=	'\033[0;34m'
PURPLE		=	'\033[0;35m'
CYAN		=	'\033[0;36m'
LIGHTGRAY	=	'\033[0;37m'
DARKGRAY	=	'\033[1;30m'
LIGHTRED	=	'\033[1;31m'
LIGHTGREEN	=	'\033[1;32m'
YELLOW		=	'\033[1;33m'
LIGHTBLUE	=	'\033[1;34m'
LIGHTPURPLE	=	'\033[1;35m'
LIGHTCYAN	=	'\033[1;36m'
WHITE		=	'\033[1;37m'

all: $(NAME)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@

$(NAME) : $(OBJS)
	@echo $(YELLOW) "==== Compilation of Libft Library==== " $(NONE)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) $(LIBFT_DIR)$(LIBFT) -o $(NAME) $(OBJS)
	@echo $(GREEN)"=============== DONE ================"$(NONE)

clean:
		@echo $(ORANGE) "========== CLEAN ==========" $(NONE)
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)
		make -C $(LIBFT_DIR) clean
		@echo $(GREEN) "=========== DONE ===========" $(NONE)
		
fclean: clean
		@echo $(ORANGE) "========== FCLEAN ==========" $(NONE)
		$(RM) $(NAME)
		make -C $(LIBFT_DIR) fclean
		@echo $(GREEN) "=========== DONE ===========" $(NONE)

re: fclean all

git: fclean
	@echo $(PURPLE) "===== PUSHING to GITHUB ===="  $(NONE)
	git add .
	git commit -m "Push_Swap - $(NOW)"
	git push origin master
	@echo $(GREEN)"=============== DONE ================"$(NONE)

norm: 
		$(NORM) $(SRC);

.PHONY: all, clean, fclean, re