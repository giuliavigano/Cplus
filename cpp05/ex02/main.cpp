#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	Bureaucrat signer("Signer", 47);
	ShrubberyCreationForm	testFormSh("Shrubbery creation");
	RobotomyRequestForm		testFormRo("Robotomy request");
	PresidentialPardonForm	testFormPr("Presidential pardon");

	try {
		signer.signForm(testFormSh);
		std::cout << "Complete form info (operator <<): " << testFormSh << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		signer.signForm(testFormRo);
		std::cout << "Complete form info (operator <<): " << testFormRo << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		signer.signForm(testFormPr);
		std::cout << "Complete form info (operator <<): " << testFormPr << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << signer.getName() << "should be able to sign Shrubbery and Robotomy form and only execute Shrubbery" << std::endl;

	try {
		signer.executeForm(testFormSh);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		signer.executeForm(testFormRo);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		signer.executeForm(testFormPr);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}