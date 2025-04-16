#include "PresidentialPardonForm.hpp"

const std::string	PresidentialPardonForm::NAME = "presidential";

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm(NAME, false, SIGN_GRADE, EXECUTE_GRADE) , target_(target) {
	std::cout << "PresidentialPardonForm: default or assignment constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form), target_(form.target_) {
	std::cout << "PresidentialPardonForm: copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm: destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form) {
	AForm::operator=(form);
	std::cout << "PresidentialPardonForm: copy assignment called" << std::endl;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	checkExecutable(executor);
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
