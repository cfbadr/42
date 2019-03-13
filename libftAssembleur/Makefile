#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/28 11:12:26 by bchoukri          #+#    #+#              #
#    Updated: 2015/05/28 17:02:09 by bchoukri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME =			libfts.a

AS =			nasm -f macho64 -w+all

SRCS =			srcs/ft_isalnum.s \
				srcs/ft_isalalpha.s \
				srcs/ft_isdigit.s \
				srcs/ft_isascii.s \
				srcs/ft_isprint.s \
				srcs/ft_tolower.s \
				srcs/ft_toupper.s \
				srcs/ft_bzero.s \
				srcs/ft_strcat.s \
				srcs/ft_strlen.s \
				srcs/ft_puts.s \
				srcs/ft_memset.s \
				srcs/ft_memcpy.s \
				srcs/ft_strdup.s \
				srcs/ft_cat.s \
				srcs/ft_isspace.s \
				srcs/ft_isblank.s \
				srcs/ft_ispunct.s \
				srcs/ft_islower.s \
				srcs/ft_isupper.s \
				main.c

INCLUDE =		-I include/

OBJS =			$(SRCS:srcs/%.s=obj/%.o)

CFLAGS =		-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		obj $(OBJS)
				@ar rc -L $(NAME) $(OBJS)
				@ranlib $(NAME)

test:
				gcc $(INCLUDE) main.c $(NAME) $(CFLAGS)

obj/%.o:		srcs/%.s
				@$(AS) -o  $@ $<
				@echo "[\033[32m√\033[m]" $<

obj:
				@mkdir -p obj

clean:
				@rm -rf obj

fclean:			clean
				@rm $(NAME)

re:				fclean all

.PHONY =		all clean fclean re
