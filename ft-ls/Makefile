#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/13 08:18:15 by bchoukri          #+#    #+#              #
#    Updated: 2015/04/19 04:49:17 by bchoukri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =      	ft_ls

SRC =			main.c \
				checkOption.c \
				sort.c \
				show.c \
				linked_list.c \
				annex.c

OBJ =			$(SRC:.c=.o)

FLAGS =			-Wall -Wextra -Werror

INCLUDES =		-I includes/ -I libft/includes/

all:			$(NAME)

$(NAME):	 	$(INCLUDES)

$(INCLUDES): 	$(OBJ)

$(OBJ): 		$(SRC)
				make -C libft/ fclean
				make -C libft/
				@gcc $(FLAGS) $(INCLUDES) -c $(SRC)
				@gcc -o $(NAME) $(OBJ) -L libft/ -lft
##				@echo "Compilation ok"
				@echo "\033[32mCompilation\033[0m"	

clean:
				@/bin/rm -f $(OBJ)

fclean: 		clean
				@/bin/rm -f $(NAME)

re: fclean all