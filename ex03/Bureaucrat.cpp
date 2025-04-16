#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
	std::cout << "Bureaucrat: Default or assignment constructor called" << std::endl;
	if (grade_ <= 0) {
		throw(GradeTooHighException());
	}
	if (150 < grade_) {
		throw(GradeTooLowException());
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& bure) : name_(bure.name_), grade_(bure.grade_) {
	std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	if (grade_ <= 0) {
		throw(GradeTooHighException());
	}
	if (150 < grade_) {
		throw(GradeTooLowException());
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator =(const Bureaucrat &bure) {
	std::cout << "Bureaucrat: copy assignment called" << std::endl;
	if (this != &bure) {
		grade_ = bure.grade_;
		if (grade_ <= 0) {
			throw(GradeTooHighException());
		}
		if (150 < grade_) {
			throw(GradeTooLowException());
		}
	}
	return *this;
}

std::string	Bureaucrat::getName(void) const {
	return name_;
}

int	Bureaucrat::getGrade(void) const {
	return grade_;
}

void	Bureaucrat::incrementGrade(void) {
	std::cout << "Bureaucrat: increment grade by 1" << std::endl;
	if (grade_ == 1) {
		throw(GradeTooHighException());
	}
	else {
		--grade_;
	}
}

void	Bureaucrat::decrementGrade(void) {
	std::cout << "Bureaucrat: decrement grade by 1" << std::endl;
	if (grade_ == 150) {
		throw(GradeTooLowException());
	}
	else {
		++grade_;
	}
}

void	Bureaucrat::signForm(AForm &form) const {
	try {
		if (form.beSigned(*this)) {
			std::cout << name_ << " signed " << form.getName() << "." << std::endl;
		}
		else {
			std::cerr << name_ << " couldn't sign " << form.getName() << " because form had been already signed." << std::endl;
		}
	}
	catch(std::exception & e) {
		(void)e;
		std::cerr << name_ << " couldn't sign " << form.getName() << " because grade was too low." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << name_ << " executed " << form.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << name_ << " failed to execute: " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bure) {
	os << bure.getName() << ", bureaucrat grade " << bure.getGrade() << ".";
	return os;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}


