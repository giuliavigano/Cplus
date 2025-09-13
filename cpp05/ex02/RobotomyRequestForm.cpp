#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Robotomy", false, 72, 45), target("unknown") {
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request", false, 72, 45), target(target) {
	std::cout << "RobotomyRequestForm parametizer constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& value) : AForm(value), target(value.target) {
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& val) {
	if (this != &val)
		this->target = val.target;
	std::cout << "RobotomyRequestForm copy assignment operator called." << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getSign()) {
		throw AForm::GradeTooLowException();
	}
	if (executor.getGrade() > getExecGrade()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << "Makes some drilling noises..." << std::endl; 
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}