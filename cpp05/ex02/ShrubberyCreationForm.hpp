#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& value);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& val);
	~ShrubberyCreationForm();

	virtual void	execute(Bureaucrat const & executor) const;
private:
	std::string	target;
};

#endif