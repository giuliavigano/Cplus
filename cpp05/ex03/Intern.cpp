#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm*	Intern::createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &value) {
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern &val) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}


// This function is an example of "factory method": create an object from a string (without the exact class of the object)
AForm*	Intern::makeForm(std::string name, std::string target) {
	
	typedef	AForm*	(*FormCreator) (const std::string&);

	struct	FormType {
		std::string formName;
		FormCreator	creator;
	};

	FormType	form[] = {
		{"shrubbery creation", &Intern::createShrubbery},
		{"robotomy request", &Intern::createRobotomy},
		{"presidential pardon", &Intern::createPresidential}	
	};

	for (int i = 0; i < 3; ++i) {
		if (form[i].formName == name) {
			std::cout << "Intern creates " << name << std::endl;
			return form[i].creator(target);
		}
	}
	std::cout << "Error: Form name not found!" << std::endl;	
	return nullptr;
}
