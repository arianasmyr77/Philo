<<<<<<< HEAD
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 11:32:51 by arforouz          #+#    #+#              #
#    Updated: 2024/06/27 15:36:09 by arforouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDE	= philo.h

SRCS = actions.c \
	init.c \
	philo.c \
	utils.c \

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=thread
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

=======
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 11:32:51 by arforouz          #+#    #+#              #
#    Updated: 2024/06/27 15:36:09 by arforouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDE	= philo.h

SRCS = actions.c \
	init.c \
	philo.c \
	utils.c \

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -g
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

>>>>>>> 00d545180b5bf7d5ad2d3d8621a7a55d2f370321
.PHONY: all clean fclean re