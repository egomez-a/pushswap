# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 11:01:24 by egomez-a          #+#    #+#              #
#    Updated: 2021/10/22 15:16:07 by egomez-a         ###   ########.fr        #
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

all: $(NAME)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@

$(NAME) : $(OBJS)
	@echo "==== Compilation of Libft Library==== "
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) $(LIBFT_DIR)$(LIBFT) -o $(NAME) $(OBJS)
	@echo "=============== DONE ================"

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