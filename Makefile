# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 11:32:51 by arforouz          #+#    #+#              #
#    Updated: 2024/07/21 11:52:29 by arforouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDE	= philo.h

SRCS = actions.c \
	init.c \
	philo.c \
	utils.c \

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra
REMOVE = rm -f

%o: %c
	@echo "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS) $(INCLUDE)
	@$(CC) $(SRCS) -o $(NAME)

all : $(NAME)

clean: 
	@$(REMOVE) $(OBJS)

fclean:
	@$(REMOVE) $(OBJS)
	@$(REMOVE) $(NAME)

re:  fclean all
