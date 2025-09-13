#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 0);
		std::cout << bob << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Error" << e.what() << std::endl;
	}
	try {
		Bureaucrat bobb("Bobb", 153);
		std::cout << bobb << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Error" << e.what() << std::endl;
 	}
	std::cout << "\n=== TEST INCREMENT GRADE ===" << std::endl;
	try {
		Bureaucrat jack("Jack", 55);
		std::cout << "Before increment: " << jack << std::endl;
		jack.incrementGrade();
		std::cout << "After increment: " << jack << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat alice("Alice", 149);
		std::cout << "Before decrement: " << alice << std::endl;
		alice.decrementGrade();
		std::cout << "After decrement: " << alice << std::endl;
		alice.decrementGrade();
		std::cout << "Shoud be too low and thrown exception !" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n=== TEST GETTERS===" << std::endl;

	Bureaucrat daniel("Daniel", 45);

	std::cout << "Name: " << daniel.getName() << std::endl;
	std::cout << "Grade: " << daniel.getGrade() << std::endl;
	return 0;
}