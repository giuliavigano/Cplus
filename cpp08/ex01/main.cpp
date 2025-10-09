/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:42:01 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/09 14:42:01 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <string>
#include <iostream>
#include <vector>

int	main() {

	std::cout << "\n=== TEST NEGATIVE PARAMETER TO THE COSTRUCTOR===" << std::endl;
	try {
		Span	sp = Span(-5);
	} catch (const Span::NotAValidSizeOfElements& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== TEST FROM SUBJECT===" << std::endl;
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	std::cout << "\n=== TEST MAX NUMBER CAPACITY EXCEPTION===" << std::endl;
	try {
		sp.addNumber(33);
	} catch (const Span::SpanAlreadyFull& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST SPAN TOO SHORT FOR MEMBER FUNCTIONS: ===" << std::endl;
	Span	spa = Span(1);

	try {
		spa.addNumber(1);
		std::cout << "For shortestSpan(): " << spa.shortestSpan() << std::endl;
	} catch (const Span::SpanTooShort& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try {
		std::cout << "For longestSpan(): " << spa.longestSpan() << std::endl;
	} catch (const Span::SpanTooShort& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST WITH A LOT OF NUMBERS===" << std::endl;
	unsigned int	n = 10000;
	Span	s = Span(n);

	for (int i = 0; (unsigned int)i < n; i++) {
		s.addNumber(i);
	}

	try {
		s.addNumber(190);
		std::cout << "Ok, there is space" << std::endl;
	} catch (const Span::SpanAlreadyFull& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "Shortest Span: " << s.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << s.longestSpan() << std::endl;

	std::cout << "\n===TEST FILL CONTAINER USING A RANGE OF ITERATORS===" << std::endl;
	std::vector<int>	numbers;

	numbers.push_back(19);
	numbers.push_back(20);
	numbers.push_back(25);
	numbers.push_back(35);
	numbers.push_back(40);

	Span	rangeNumber(numbers.size());
	rangeNumber.addNumbers(numbers.begin(), numbers.end());
	std::cout << "Shortest Span: " << rangeNumber.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << rangeNumber.longestSpan() << std::endl;

	try {
		rangeNumber.addNumber(10);
		std::cout << "Ok, number added!" << std::endl;
	} catch (const Span::SpanAlreadyFull& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}