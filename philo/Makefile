# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkotbi <hibenouk@1337.ma>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 20:17:26 by zkotbi            #+#    #+#              #
#    Updated: 2024/04/17 11:06:46 by zkotbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= philo/philo.c\
		  philo/init_philo.c\
		  philo/parsing.c

OBJ 	= $(SRC:.c=.o)

NAME	= philo

CC = cc


CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC)  $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c philo.h
	$(CC) -c $(CFLAGS) $< -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all
