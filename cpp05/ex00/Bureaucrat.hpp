#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& value);
	Bureaucrat& operator=(const Bureaucrat& val);
	~Bureaucrat(void);
	void		incrementGrade();
	void		decrementGrade();
	int			getGrade() const;
	const std::string getName() const;

	// Custom exceptions (specific to Bureaucrat class) [Exceptions belong with the class that uses them]
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade cannot be less than HIGHEST_GRADE = 1 !";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade cannot be higher than LOWEST_GRADE = 150 !";
		}
	};

private:
	std::string const name;
	int		grade;

	// Constants for grade limits (exception boundaries)
	static const int	HIGHEST_GRADE = 1;
	static const int	LOWEST_GRADE = 150;

	int		validateGrade(int grade) const;

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif
