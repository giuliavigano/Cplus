# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 16:21:31 by gvigano           #+#    #+#              #
#    Updated: 2025/10/16 16:21:31 by gvigano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= btc

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC				= main.cpp \
					BitcoinExchange.cpp

OBJ				= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all