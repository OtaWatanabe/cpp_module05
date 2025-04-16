#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	Form form1("form1", false, 50, 100);
	Form form2("form2", false, 1, 100);
	Form form3(form1);
	Form form4;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
	std::cout << form4 << std::endl;
	form4 = form1;
	std::cout << form4 << std::endl;

	std::cout << "check get functions" << std::endl;
	std::cout << "name: " << form1.getName() << std::endl;
	std::cout << "isSigned: " << form1.getIsSigned() << std::endl;
	std::cout << "gradeToSign: " << form1.getGradeToSign() << std::endl;
	std::cout << "gradeToExecute: " << form1.getGradeToExecute() << std::endl;

	Bureaucrat bure("bure", 50);
	try {
		form1.beSigned(bure);
		std::cout << "form1: succeeded in signing" << std::endl;
	}
	catch(std::exception & e) {
		std::cout << "form1: " << e.what() << std::endl;
	}
	try {
		form2.beSigned(bure);
		std::cout << "form2: succeeded in signing" << std::endl;
	}
	catch(std::exception & e) {
		std::cout << "form2: " << e.what() << std::endl;
	}
	bure.signForm(form1);
	bure.signForm(form2);
	bure.signForm(form3);
}
