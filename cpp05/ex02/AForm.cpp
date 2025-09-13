#include "AForm.hpp"
#include "Bureaucrat.hpp" // include complete class to use her methods

std::ostream& operator<<(std::ostream& out, const AForm& AForm) {
	out << "AForm: " << AForm.getAFormName()
		<< ", signed: " << (AForm.getSign() ? "yes" : "no")
		<< ", sign grade: " << AForm.getSignGrade()
		<< ", exec grade: " << AForm.getExecGrade();
	return out;
}

AForm::AForm(const std::string& name, bool sign, const int signGrade, const int execGrade) : name(name), sign(sign),  signGrade(signGrade), execGrade(execGrade) {
	if (signGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150)
		throw GradeTooLowException();
	if (execGrade < 1)
		throw GradeTooHighException();
	if (execGrade > 150)
		throw GradeTooLowException();
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm& value) : name(value.name), sign(value.sign), signGrade(value.signGrade), execGrade(value.execGrade) {
	std::cout << "AForm copy constructor called." << std::endl;
}

AForm&	AForm::operator=(const AForm& val) {
	if (this != &val) {
		this->sign = val.sign;
		std::cout << "Note: const members (name, signGrade, execGrade) cannot be reassigned !" << std::endl;
	}
	std::cout << "AForm copy assignment operator called." << std::endl;
	return *this;
}

AForm::~AForm(void) {
	std::cout << "AForm default destructor called" << std::endl;
}

bool AForm::getSign() const {
	return sign;
}

int AForm::getSignGrade() const {
	return signGrade;
}

int AForm::getExecGrade() const {
	return execGrade;
}

std::string AForm::getAFormName() const {
	return name;
}

void AForm::beSigned(const Bureaucrat& name) {
	if (name.getGrade() <= signGrade)
		this->sign = true;
	else
		throw GradeTooLowException();
}