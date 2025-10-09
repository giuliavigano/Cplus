/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:42:08 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/09 14:42:08 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

Span::Span(unsigned int N) : _maxSize(verifyN(N)), _span() {}

Span::Span(const Span& value) : _maxSize(value._maxSize), _span(value._span) {}

Span&	Span::operator=(const Span& val) {
	if (this != &val) {
		_maxSize = val._maxSize;
		_span = val._span;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int n) {
	if (_span.size() >= _maxSize)
		throw SpanAlreadyFull();
	_span.push_back(n);
}

unsigned int	Span::shortestSpan() {
	unsigned int		diff;
	unsigned int		min_diff;

	if (_span.size() < 2)
		throw SpanTooShort();
	diff = 0;
	std::vector<int> sorting(_span);
	std::sort(sorting.begin(), sorting.end());
	min_diff = static_cast<unsigned int> (sorting[1] - sorting[0]);
	for (size_t i = 2; i < sorting.size(); ++i) {
		diff = static_cast<unsigned int>(sorting[i] - sorting[i - 1]);
		if (diff < min_diff)
			min_diff = diff;
	}
	return min_diff;
}

unsigned int	Span::longestSpan() {
	if (_span.size() < 2)
		throw SpanTooShort();
	std::vector<int> sorting(_span);
	std::sort(sorting.begin(), sorting.end());
	return static_cast<unsigned int>(sorting.back() - sorting.front());
}

unsigned int	Span::verifyN(unsigned int n) {
	if (n > static_cast<unsigned int>(std::numeric_limits<int>::max()))
		throw NotAValidSizeOfElements();
	else
		return n;
}