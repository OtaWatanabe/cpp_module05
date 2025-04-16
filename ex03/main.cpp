#include "Intern.hpp"
#include "Bureaucrat.hpp"

int	main() {
	Intern	intern;
	AForm* form;
	Bureaucrat	bure("bure", 1);

	std::string	formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation", "no"};
	for (int i = 0; i < 3; ++i) {
		form = intern.makeForm(formNames[i], "target");
		if (form) {
			bure.signForm(*form);
			bure.executeForm(*form);
			delete form;
		}
	}
}
