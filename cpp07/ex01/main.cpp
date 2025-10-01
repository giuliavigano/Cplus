#include "iter.hpp"

void	print_int(const int value) {
	std::cout << value << std::endl;
}

void	increment(int& value) {
	value++;
}

void	print_string(const std::string value) {
	std::cout << value << std::endl;
}

void	uppercase(std::string& value) {
	for (size_t i = 0; i < value.length(); i++)
		value[i] = std::toupper(value[i]);
}

int	main() {
	int arr[] = {1, 2, 3, 4, 5};
	std::string	str[] = {"hello", "to", "my", "people"};

	std::cout << "\n=== TEST INT ARRAY===" << std::endl;
	::iter(arr, 5, print_int);
	::iter(arr, 5, increment);
	::iter(arr, 5, print_int);

	std::cout << "\n=== TEST STRING ARRAY===" << std::endl;
	::iter(str, 4, print_string);
	::iter(str, 4, uppercase);
	::iter(str, 4, print_string);

	std::cout << "\n=== TEST INSTANTIATED FUNCTION TEMPLATE===" << std::endl;
	::iter(arr, 5, print<int>);
	::iter(str, 4, print<std::string>);

	return 0;
}