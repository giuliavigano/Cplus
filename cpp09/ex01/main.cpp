#include "RPN.hpp"
int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: bad input." << std::endl;
		return 1;
	}
	RPN		expression;
	expression.evaluate(argv[1]);
	return 0;
}