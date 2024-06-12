# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 19:43:34 by arforouz          #+#    #+#              #
#    Updated: 2024/05/16 19:43:42 by arforouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philo.h

CC = gcc
fclean: clean
		@rm -f $(NAME)

re:  fclean all

.PHONY: all clean fclean re