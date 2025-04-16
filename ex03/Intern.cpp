#include "Intern.hpp"

Intern::Intern(void) {
    std::cout << "Intern: default constructor called" << std::endl;
}

Intern::Intern(const Intern& intern) {
	(void)intern;
    std::cout << "Intern: default constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern: destructor called" << std::endl;
}

Intern& Intern::operator =(const Intern &intern) {
	(void)intern;
	std::cout << "Intern: copy assignment called" << std::endl;
	return *this;
}

static AForm*	makePresidential(const std::string& target) {
	return new PresidentialPardonForm(target);	
}

static AForm*	makeRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);	
}

static AForm*	makeShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);	
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const {
    AForm   *ret;
	std::string	formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* (*funcs[])(const std::string& target) = {makePresidential, makeRobotomy, makeShrubbery};

	for (int i = 0; i < 3; ++i) {
		if (formNames[i] == formName) {
			ret = funcs[i](target);
			std::cout << "Intern creates " << ret->getName() << std::endl;
			return ret;
		}
	}
	std::cerr << "No name matches for " << formName << std::endl;
	return NULL;
}
