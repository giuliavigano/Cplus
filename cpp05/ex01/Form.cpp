#include "Form.hpp"
#include "Bureaucrat.hpp" // include complete class to use her methods

std::ostream& operator<<(std::ostream& out, const Form& Form) {
	out << "Form: " << Form.getFormName()
		<< ", signed: " << (Form.getSign() ? "yes" : "no")
		<< ", sign grade: " << Form.getSignGrade()
		<< ", exec grade: " << Form.getExecGrade();
	return out;
}

Form::Form() : name("Default"), sign(false), signGrade(42), execGrade(20) {
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string& name, bool sign, const int signGrade, const int execGrade) : name(name), sign(sign),  signGrade(signGrade), execGrade(execGrade) {
	if (signGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150)
		throw GradeTooLowException();
	if (execGrade < 1)
		throw GradeTooHighException();
	if (execGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form& value) : name(value.name), sign(value.sign), signGrade(value.signGrade), execGrade(value.execGrade) {
	std::cout << "Form copy constructor called." << std::endl;
}

Form&	Form::operator=(const Form& val) {
	if (this != &val) {
		this->sign = val.sign;
		std::cout << "Note: const members (name, signGrade, execGrade) cannot be reassigned !" << std::endl;
	}
	std::cout << "Form copy assignment operator called." << std::endl;
	return *this;
}

Form::~Form(void) {
	std::cout << "Form default destructor called" << std::endl;
}

bool Form::getSign() const {
	return sign;
}

int Form::getSignGrade() const {
	return signGrade;
}

int Form::getExecGrade() const {
	return execGrade;
}

std::string Form::getFormName() const {
	return name;
}

void Form::beSigned(const Bureaucrat& name) {
	if (name.getGrade() <= signGrade)
		this->sign = true;
	else
		throw GradeTooLowException();
}