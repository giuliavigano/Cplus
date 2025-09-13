#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery", false, 145, 137), target("default") {
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

// è giusto mettere in input false alla creazione di shruberry form ?
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation", false, 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm parametrizer contructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& value) : AForm(value), target(value.target) {
	std::cout << "Shrubbery copy constructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& val) {
	if (this != &val)
		this->target = val.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm () {
	std::cout << "Shrubbery destructor called." << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::ofstream file((this->target + "_shrubbery").c_str());
	if (!file)
		throw AForm::FileErrorException();
	else {
		file << "      /\\\n"
			 << "     /  \\\n"
			 << "    /++++\\\n"
			 << "   /  ()  \\\n"
			 << "  /________\\\n"
			 << "     ||\n"
			 << "     ||\n";
		file.close();
	}
}
