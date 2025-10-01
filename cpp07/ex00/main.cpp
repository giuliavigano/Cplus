#include "whatever.hpp"

int main() {
	int a = 3;
	int b = 5;

	::swap(a, b);
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "min(a,b): " << ::min(a,b) << std::endl;
	std::cout << "max(a,b): " << ::max(a,b) << std::endl;

	std::string c = "Hello1";
	std::string d = "Hello2";

	::swap(c, d);
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "min(c, d): " << ::min(c, d) << std::endl;
	std::cout << "max(c, d): " << ::max(c, d) << std::endl;

	return 0;
}