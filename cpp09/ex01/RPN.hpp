#ifndef RPN_HPP
# define RPN_HPP
#include <stack>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>

class RPN {
public:
	RPN();
	RPN(const RPN& value);
	RPN& operator=(const RPN& val);
	~RPN();

	int		calculate(int a, int b, char c);
	void	evaluate(const std::string& input);

private:
	std::stack<int>	expression;

	bool	isOperator(char c);
	bool	isDigit(char c);
};

#endif