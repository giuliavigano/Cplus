#ifndef ITER_HPP
# define ITER_HPP
#include <cmath>
#include <cctype>
#include <string>
#include <iostream>

template<typename N>
void	print(const N value) {
	std::cout << value << std::endl;
}

template<typename N, typename Func>
void	iter(N* arr, const int size, Func function) {
	for (int i = 0; i < size; i++)
		function(arr[i]);
}

#endif