#include "easyfind.hpp"
#include <iostream>

int	main() {
	std::cout << "\n=== TEST TYPE VECTOR CONTAINERS===" << std::endl;
	std::vector<int> arr;
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(1);

	try {
		std::vector<int>::iterator value = easyfind(arr, 3);
		std::cout << "success!! -> result: " << *value << std::endl;
	} catch (NotInThereException& e) {
		std::cout << "failure!! -> " << e.what() << std::endl;
	}
	try {
		std::vector<int>::iterator value = easyfind(arr, 7);
		std::cout << "success!! -> result: " << *value << std::endl;
	} catch (NotInThereException& e) {
		std::cout << "failure!! -> " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST TYPE DEQUE CONTAINERS===" << std::endl;
	std::deque<int> dq;
	dq.push_back(5);
	dq.push_front(4);
	dq.push_back(6);
	dq.push_front(2);
	dq.push_back(8);

	try {
		std::deque<int>::iterator value = easyfind(dq, 2);
		std::cout << "success!! -> result: " << *value << std::endl;
	} catch (const NotInThereException& e) {
		std::cout << "failure!! -> " << e.what() << std::endl;
	}
	try {
		std::deque<int>::iterator value = easyfind(dq, 9);
		std::cout << "success!! -> result: " << *value << std::endl;
	} catch (const NotInThereException& e) {
		std::cout << "failure!! -> " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST TYPE LIST CONTAINERS===" << std::endl;
	std::list<int> lis;

	lis.push_back(9);
	lis.push_front(8);
	lis.push_back(10);
	lis.push_front(7);
	lis.push_back(11);

	try {
		std::list<int>::iterator value = easyfind(lis, 8);
		std::cout << "success!! -> result: " << *value << std::endl;
	} catch (const NotInThereException& e) {
		std::cout << "failure!! -> " << e.what() << std::endl;
	}
	try {
		std::list<int>::iterator value = easyfind(lis, 4);
		std::cout << "success!! -> result: " << *value << std::endl;
	} catch (const NotInThereException& e) {
		std::cout << "failure!! -> " << e.what() << std::endl;
	}
	return 0;
}