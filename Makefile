# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 17:03:56 by denizozd          #+#    #+#              #
#    Updated: 2023/11/25 22:51:55 by denizozd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Variables	#
NAME = libftprintf.a
LIBNAME = libft.a
LIBDIR = ./libft

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c print_char.c print_str.c print_ptr.c print_int.c\
	print_uns.c print_hex.c
OBJS = ${SRCS:.c=.o}

#	Targets		#
all: $(NAME)

makelib:
	make -C $(LIBDIR)
	cp $(LIBDIR)/$(LIBNAME) .
	mv $(LIBNAME) $(NAME)

$(NAME): makelib $(OBJS)
	ar -r $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean

re: fclean all

.PHONY: all makelib clean fclean re
