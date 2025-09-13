#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <string>
#include <exception>

// tell Form that this class exist
class Bureaucrat; 

class Form {
public:
	Form();
	Form (const std::string& name, bool sign, const int signGrade, const int execGrade);
	Form(const Form& value);
	Form& operator=(const Form& val);
	~Form(void);
	
	bool		getSign() const;
	int		getSignGrade() const;
	int		getExecGrade() const;
	std::string	getFormName() const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form grade is too high";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form grade is too low";
		}
	};

	void	beSigned(const Bureaucrat& name);
	
private:
	const std::string name;
	bool	sign;
	const int		signGrade;
	const int		execGrade;
};

std::ostream& operator<<(std::ostream& out, const Form& Form);

#endif