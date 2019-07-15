# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcodi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:56:52 by fcodi             #+#    #+#              #
#    Updated: 2019/07/15 12:11:53 by fcodi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Iincludes -MD -pipe -o $@

LIB_MAKE = $(MAKE) -C $(LIB_DIR)

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

NAME = fillit

SRC = main.c prelude.c utils.c

OBJ = $(SRC:.c=.o)

MD = $(SRC:.c=.d)

all: $(LIB_DIR)/%.c $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) -Llibft -lft $(OBJ)

$(LIB_DIR)/%.c:
	$(LIB_MAKE)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

fclean: clean
	$(RM) $(NAME)
	$(LIB_MAKE) fclean

clean:
	$(RM) $(MD)
	$(RM) $(OBJ)
	$(LIB_MAKE) clean

re: fclean all
