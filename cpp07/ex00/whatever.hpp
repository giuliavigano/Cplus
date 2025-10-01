#ifndef WHATEVER_HPP
# define WHATEVER_HPP
#include <iostream>

template<typename N>
void	swap(N& a, N& b) {
	N	c;

	c = a;
	a = b;
	b = c;
}

template<typename N>
N	min(N a, N b) {
	if (a == b)
		return b;
	else
		return (a < b) ? a : b;
}

template<typename N>
N	max(N a, N b) {
	if (a == b)
		return b;
	else
		return (a > b) ? a : b;
}

#endif