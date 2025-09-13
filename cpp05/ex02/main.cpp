#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat ceo("Bob", 1);
		Bureaucrat	menager("Jack", 21);
		Bureaucrat	intern("Daniel", 111);

		Form form1("First", false, 5, 3);
		Form form2("Second", false, 45, 34);

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;

		ceo.signForm(form1);
		menager.signForm(form1);
		intern.signForm(form2);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST GETTER AND OUTPUT===" << std::endl;
	Form testForm("TestForm", false, 46, 24);

	std::cout << "Form name: " << testForm.getFormName() << std::endl;
	std::cout << "Is signed: " << (testForm.getSign() ? "true" : "false") << std::endl;
	std::cout << "Sign grade: " << testForm.getSignGrade() << std::endl;
	std::cout << "Exec grade: " << testForm.getExecGrade() << std::endl;
	
	std::cout << "Complete form info (operator<<): " << testForm << std::endl;

	Bureaucrat signer("Signer", 39);
	signer.signForm(testForm);

	std::cout << "After signing:" << std::endl;
	std::cout << "Is signed: " << (testForm.getSign() ? "yes" : "no") << std::endl;
	std::cout << "Complete form info (operator <<): " << testForm << std::endl;
	
	return 0;
}