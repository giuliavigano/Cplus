/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:03:49 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/22 12:03:50 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				int	b = expression.back();
				expression.pop_back();
				int	a = expression.back();
				expression.pop_back();
				if (token[0] == '/' && b == 0) {
					std::cout << "Error: division by zero." << std::endl;
					return;
				}
				expression.push_back(calculate(a, b , token[0]));
				continue;
			}
			else if (isDigit(token[0]) && std::atoi(token.c_str()) < 10 ) {
				expression.push_back(std::atoi(token.c_str()));
				continue;
			}
			std::cout << "Error: bad input." << std::endl;
			continue;
		}
	}
	if (expression.size() != 1) {
		std::cout << "Error: invalid expression." << std::endl;
		return;
	}
	std::cout << expression.back() << std::endl;
}
