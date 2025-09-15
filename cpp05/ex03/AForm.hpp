#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

// tell AForm that this class exist
//class Bureaucrat; 

class AForm {
public:
	AForm (const std::string& name, bool sign, const int signGrade, const int execGrade);
	AForm(const AForm& value);
	AForm& operator=(const AForm& val);
	virtual ~AForm(void);
	
	std::string	getAFormName() const;
	bool 	getSign()const;
	int		getSignGrade() const;
	int		getExecGrade() const;
	void	beSigned(const Bureaucrat& name);

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

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form not signed, cannot execute !";
		}
	};

	class FileErrorException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Failed to open file!";
		}
	};

	virtual void	execute(Bureaucrat const & executor) const = 0;
	
private:
	const std::string name;
	bool	sign;
	const int		signGrade;
	const int		execGrade;
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif