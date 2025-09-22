#include "Functions.hpp"

int	main() {
	Base* 	p1;
	Base*	p2;
	Base*	p3;

	srand(time(NULL));
	p1 = generate();
	p2 = generate();
	p3 = generate();

	std::cout << "=== Test identify with pointers===" << std::endl;
	identify(p1);
	identify(p2);
	identify(p3);

	std::cout << "=== Test identify with references===" << std::endl;
	identify(*p1);
	identify(*p2);
	identify(*p3);

	delete 	p1;
	delete 	p2;
	delete	p3;
	return 0;
}