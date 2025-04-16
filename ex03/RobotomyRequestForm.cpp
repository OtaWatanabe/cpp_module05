#include "RobotomyRequestForm.hpp"

const std::string	RobotomyRequestForm::NAME = "robotomy";

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm(NAME, false, SIGN_GRADE, EXECUTE_GRADE) , target_(target) {
	std::srand(std::time(0));
	std::cout << "RobotomyRequestForm: default or assignment constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form), target_(form.target_) {
	std::srand(std::time(0));
	std::cout << "RobotomyRequestForm: copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm: destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form) {
	AForm::operator=(form);
	std::cout << "RobotomyRequestForm: copy assignment called" << std::endl;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkExecutable(executor);
	std::cout << "drdrdrdr" << std::endl;
	if (std::rand() % 2) std::cout << target_ << " has been successfully robotomized!" << std::endl;
	else std::cout << target_ << " couldn't be robotomized" << std::endl;
}
