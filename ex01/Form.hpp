#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	name_;
	bool	isSigned_;
	const int	gradeToSign_;
	const int	gradeToExecute_;

public:
	Form(std::string name="default", bool isSigned=false, int gradeToSign=100, int gradeToExecute=50);
	Form(const Form &form);
	Form& operator=(const Form& form);
	~Form();
	std::string	getName(void) const;
	bool	getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool	beSigned(const Bureaucrat& bure);
	class GradeTooHighException : public std::exception {
	public:
		const char * what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char * what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form &form);

#endif
