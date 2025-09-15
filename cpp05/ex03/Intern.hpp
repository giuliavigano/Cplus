#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& value);
	Intern& operator=(const Intern& val);
	~Intern();

	static	AForm*	createRobotomy(const std::string& target);
	static	AForm*	createShrubbery(const std::string& target);
	static	AForm*	createPresidential(const std::string& target);

	AForm*	makeForm(std::string formName, std::string target);
private:
};

#endif