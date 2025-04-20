# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 11:32:51 by arforouz          #+#    #+#              #
#    Updated: 2024/07/25 11:47:15 by arforouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDE	= philo.h

SRCS = actions.c \
	checks.c \
	init.c \
	main.c \
	utils.c \

CC		= gcc

CFLAGS	=	-Wall -Werror -Wextra -pthread #-g3 -fsanitize=thread

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
