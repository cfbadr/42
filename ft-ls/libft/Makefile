#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/12 18:58:44 by bchoukri          #+#    #+#              #
#    Updated: 2015/02/04 18:24:15 by bchoukri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = ft_strlen.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_fd.c ft_putendl.c\
	   ft_strclr.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
	   ft_strncat.c ft_strchr.c ft_isalpha.c ft_strequ.c ft_strjoin.c get_next_line.c\
	   ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c\
	   ft_toupper.c ft_atoi.c ft_strrchr.c ft_strlcat.c ft_strnequ.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strsplit.c ft_intcmp.c \
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c \
	   ft_memmove.c ft_memalloc.c ft_strsub.c ft_strtrim.c ft_strcmp.c\
	   ft_strnew.c ft_strncmp.c ft_itoa.c ft_memcmp.c ft_strstr.c ft_strnstr.c\
	   ft_memdel.c ft_strdel.c ft_striteri.c ft_striter.c ft_strmap.c ft_strmapi.c

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c $(SRCS) $(FLAGS) -I ./includes
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[32mlibft.a was created\033[0m"

norm:
	@echo "\033[32mnorminette...\033[0m"
	@norminette $(SRCS)

rm:
	@rm -f check
	@rm -f test

clean:
	@rm -f $(OBJS)
	@echo "\033[32msuppression .o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32msuppression libft.a\033[0m"

re: fclean all 

.PHONY = all clean fclean re
