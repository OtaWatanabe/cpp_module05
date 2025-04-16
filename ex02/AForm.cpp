#include "AForm.hpp"

AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute):
	name_(name), isSigned_(isSigned), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
	std::cout << "AForm: Default or assignement constructor called" << std::endl;
	if (gradeToSign_ <= 0 || gradeToExecute <= 0) {
		throw(GradeTooHighException());
	}
	if (150 < gradeToSign_ || 150 < gradeToExecute) {
		throw(GradeTooLowException());
	}
}

AForm::AForm(const AForm &form): name_(form.name_), isSigned_(form.isSigned_),
	gradeToSign_(form.gradeToSign_), gradeToExecute_(form.gradeToExecute_) {
	std::cout << "AForm: Copy constructor called" << std::endl;
	if (gradeToSign_ <= 0 || gradeToExecute_ <= 0) {
		throw(GradeTooHighException());
	}
	if (150 < gradeToSign_ || 150 < gradeToExecute_) {
		throw(GradeTooLowException());
	}
}

AForm::~AForm() {
	std::cout << "AForm: Destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& form) {
	std::cout << "AForm: copy assingment called" << std::endl;
	if (this != &form) {
		isSigned_ = form.isSigned_;
	}
	return *this;
}

std::string	AForm::getName(void) const {
	return name_;
}

bool	AForm::getIsSigned(void) const {
	return isSigned_;
}

int	AForm::getGradeToSign(void) const {
	return gradeToSign_;
}

int AForm::getGradeToExecute(void) const {
	return gradeToExecute_;
}

bool	AForm::beSigned(const Bureaucrat &bure) {
	if (gradeToSign_ < bure.getGrade()) {
		throw(GradeTooLowException());
	}
	if (isSigned_) return false;
	isSigned_ = true;
	return true;
}

void	AForm::checkExecutable(const Bureaucrat& bure) const {
	if (!isSigned_) {
		throw(NoSignException());
	}
	if (gradeToExecute_ < bure.getGrade()) {
		throw(GradeTooLowException());
	}
}

const char*	AForm::GradeTooHighException::what(void) const throw() {
	return "Grade is too high";
}

const char*	AForm::GradeTooLowException::what(void) const throw() {
	return "Grade is too low";
}

const char*	AForm::NoSignException::what(void) const throw() {
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm &form) {
	os << form.getName() << " is ";
	if (form.getIsSigned()) os << "signed.\n";
	else os << "not signed.\n";
	os << "Grade required to sign is " << form.getGradeToSign() << ", grade required to execute is " << form.getGradeToExecute() << ".";
	return os;
}
