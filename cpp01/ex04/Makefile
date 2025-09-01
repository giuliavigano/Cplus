NAME		= replaced

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp \
				Replace.cpp

OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

TESTER_NAME	:= tester.sh
TESTER_URL	:= https://raw.githubusercontent.com/jollagit/42Projects/main/CPP%2B%2B/testers/tester.sh

test:
	@if [ "$(TESTER_URL)" ]; then \
		if [ ! -f "$(TESTER_NAME)" ]; then \
			echo "Downloading tester"; \
			curl -sSfL $(TESTER_URL) -o $(TESTER_NAME); \
			if [ -f "$(TESTER_NAME)" ]; then \
				chmod +x $(TESTER_NAME); \
				echo "Done"; \
			else \
				echo "Not a valid URL"; \
			fi; \
		else \
			echo "File already exists"; \
		fi; \
	else \
		echo "Empty URL"; \
	fi;

re: fclean all 	
.PHONY: re clean fclean all test