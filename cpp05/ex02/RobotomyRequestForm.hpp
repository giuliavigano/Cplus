#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& value);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& val);
	~RobotomyRequestForm();

	virtual void	execute(Bureaucrat const & executor) const;
private:
	std::string target;
};

#endif