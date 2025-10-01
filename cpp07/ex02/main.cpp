#include "Array.hpp"
#include <iostream>
#include <string>

int	main() {
	std::cout << "\n=== TEST TEMPLATE FUNCTION IN OCF===" << std::endl;
	Array<int>	default_arr;
	Array<int>	arr(5);
	Array<int>	assign;
	assign = arr;

	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 2;

	Array<int>	copy(arr);
	
	Array<std::string>	default_str;
	Array<std::string>	str(3);
	Array<std::string>	str_assign;
	str_assign = str;

	for (unsigned int i = 0; i < str.size(); i++)
		str[i] += "h";

	Array<std::string>	str_copy(str);

	std::cout << "\n=== TEST ELEMENTS ACCESS THROUGH [] OPERATOR===" << std::endl;
	
	std::cout << "Element 3 of array arr: " << arr[3]
			  << "\n Element 3 of array copy (copy of arr): "
			  << copy[3] << std::endl;

	std::cout << "Element 2 of array str: " << str[2]
			  << "\n Element 2 of array copy (str): "
			  << str_copy[2] << std::endl;

	std::cout << "\n=== TEST RETURN SIZE===" << std::endl;

	unsigned int def_size = default_arr.size();
	unsigned int arr_size = arr.size();
	unsigned int copy_size = copy.size();
	
	std::cout << "Size of default array: " << def_size << std::endl;
	std::cout << "Size of arr: " << arr_size << std::endl;
	std::cout << "Size of copy: " << copy_size << std::endl;

	unsigned int	def_str_size = default_str.size();
	unsigned int	str_size = str.size();
	unsigned int	str_copy_size = str_copy.size();

	std::cout << "Size of default string array: " << def_str_size << std::endl;
	std::cout << "Size of string array str: " << str_size << std::endl;
	std::cout << "Size of str_copy (copy of string array str): " << str_copy_size << std::endl;

	return 0;
}