#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat) {
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return out;
}

Bureaucrat::Bureaucrat() : name("Default"), grade(validateGrade(1)) {
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(validateGrade(grade)) {
	std::cout << "Bureaucrat parametrized constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& value) : name(value.name), grade(value.grade) {
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& val) {
	if (this != &val) {
		this->grade = val.grade;
		std::cout << "Note: we can reassign only grade because name is a const member." << std::endl;
	}
	std::cout << "Bureaucrat copy assignment operator called !" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat default destructor called." << std::endl;
}

int Bureaucrat::getGrade() const {
	return grade;
}

const std::string Bureaucrat::getName() const {
	return this->name;
}

void Bureaucrat::decrementGrade() {
	if (grade + 1 > LOWEST_GRADE)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::incrementGrade() {
	if (grade -1 < HIGHEST_GRADE)
		throw GradeTooHighException();
	grade--;
}

int Bureaucrat::validateGrade(int grade) const{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	return grade;
}
