NAME		= megaphone

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
		$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
		rm -f $(NAME)

re: clean all

.PHONY: re clean all