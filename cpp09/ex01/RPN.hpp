/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:03:58 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/22 12:03:59 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
#include <list>
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
	std::list<int>	expression;

	bool	isOperator(char c);
	bool	isDigit(char c);
};

#endif