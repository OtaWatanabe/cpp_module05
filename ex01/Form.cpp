#include "Form.hpp"

Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute):
	name_(name), isSigned_(isSigned), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
	std::cout << "Form: Default or assignement constructor called" << std::endl;
	if (gradeToSign_ <= 0 || gradeToExecute <= 0) {
		throw(Form::GradeTooHighException());
	}
	if (150 < gradeToSign_ || 150 < gradeToExecute) {
		throw(Form::GradeTooLowException());
	}
}

Form::Form(const Form &form): name_(form.name_), isSigned_(form.isSigned_),
	gradeToSign_(form.gradeToSign_), gradeToExecute_(form.gradeToExecute_) {
	std::cout << "Form: Copy constructor called" << std::endl;
	if (gradeToSign_ <= 0 || gradeToExecute_ <= 0) {
		throw(Form::GradeTooHighException());
	}
	if (150 < gradeToSign_ || 150 < gradeToExecute_) {
		throw(Form::GradeTooLowException());
	}
}

Form::~Form() {
	std::cout << "Form: Destructor called" << std::endl;
}

Form& Form::operator=(const Form& form) {
	std::cout << "Form: copy assingment called" << std::endl;
	if (this != &form) {
		isSigned_ = form.isSigned_;
	}
	return *this;
}

std::string	Form::getName(void) const {
	return name_;
}

bool	Form::getIsSigned(void) const {
	return isSigned_;
}

int	Form::getGradeToSign(void) const {
	return gradeToSign_;
}

int Form::getGradeToExecute(void) const {
	return gradeToExecute_;
}

bool	Form::beSigned(const Bureaucrat &bure) {
	if (gradeToSign_ < bure.getGrade()) {
		throw(GradeTooLowException());
	}
	if (isSigned_) return false;
	isSigned_ = true;
	return true;
}

const char*	Form::GradeTooHighException::what(void) const throw() {
	return "Grade is too high";
}

const char*	Form::GradeTooLowException::what(void) const throw() {
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form &form) {
	os << form.getName() << " is ";
	if (form.getIsSigned()) os << "signed.\n";
	else os << "not signed.\n";
	os << "Grade required to sign is " << form.getGradeToSign() << ", grade required to execute is " << form.getGradeToExecute() << "." << std::endl;
	return os;
}
