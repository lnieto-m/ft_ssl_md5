# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/11 11:57:03 by lnieto-m          #+#    #+#              #
#    Updated: 2018/06/24 13:51:50 by lnieto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= ft_ssl
CC 	 		= gcc -Wall -Wextra -Werror


LIBS		= -L libft/ -lft -lm

SRC  		= main.c \
			md5.c \

OBJ  		= $(SRC:%.c=objs/%.o)


SRC_DIR 	= ./srcs
INCLUDE_DIR = -I ./incs/ -I libft/includes

all: objs $(NAME)

objs:
	@mkdir objs

$(NAME): $(OBJ)
	make -C libft/ all
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

objs/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -o $@ -c $<

clean:
	rm -rf objs
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
