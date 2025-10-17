#include "RPN.hpp"

RPN::RPN() : expression() {}

RPN::RPN(const RPN& value) : expression(value.expression) {}

RPN&	RPN::operator=(const RPN& val) {
	if (this != &val)
		this->expression = val.expression;
	return *this;
}

RPN::~RPN() {}

bool	RPN::isOperator(char c) {
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool	RPN::isDigit(char c) {
	return (std::isdigit(static_cast<unsigned char>(c)));
}

int		RPN::calculate(int a, int b, char c) {
	switch (c) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '/':
			return a / b;
		case '*':
			return a * b;
	}
	return 1;
}

void		RPN::evaluate(const std::string& input) {
	std::istringstream	elem(input);
	std::string			token;

	while (elem >> token) {
		if (token.length() == 1) {
			if (isOperator(token[0])) {
				if (expression.size() < 2) {
					std::cout << "Error: insufficient operands." << std::endl;
					return;
				}
				int	b = expression.top();
				expression.pop();
				int	a = expression.top();
				expression.pop();
				if (token[0] == '/' && b == 0) {
					std::cout << "Error: division by zero." << std::endl;
					return;
				}
				expression.push(calculate(a, b , token[0]));
				continue;
			}
			else if (isDigit(token[0]) && std::atoi(token.c_str()) < 10 ) {
				expression.push(std::atoi(token.c_str()));
				continue;
			}
			std::cout << "Error: bad input." << std::endl;
			continue;
		}
	}
	std::cout << expression.top() << std::endl;
}
