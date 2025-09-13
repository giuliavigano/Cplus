#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Shrubbery", false, 25, 5), target("unknown") {
	std::cout << "PresidentialPardonForm default contructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon", false, 25, 5), target(target) {
	std::cout << "PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& value) : AForm(value), target(value.target) {
	std::cout << "PresidentialPardonForm copy contructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& val) {
	std::cout << "PresidentialPardonForm copy assignment operator called." << std::endl;
	if (this != &val)
		this->target = val.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}