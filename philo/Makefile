# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 00:04:29 by zkotbi            #+#    #+#              #
#    Updated: 2024/04/24 00:07:51 by zkotbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= philo.c\
		  init_philo.c\
		  input_error.c\
		  ft_atoi.c\
		  free.c\
		  dining_philo.c\
		  routine.c\
		  superviser.c\
		  activity.c\
		  time.c

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
