#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	name_;
	bool	isSigned_;
	const int	gradeToSign_;
	const int	gradeToExecute_;

public:
	AForm(std::string name="default", bool isSigned=false, int gradeToSign=100, int gradeToExecute=50);
	AForm(const AForm &form);
	AForm& operator=(const AForm& form);
	virtual	~AForm();
	std::string	getName(void) const;
	bool	getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool	beSigned(const Bureaucrat& bure);
	void	checkExecutable(const Bureaucrat& bure) const;
	virtual void	execute(const Bureaucrat & executor) const = 0;
	class GradeTooHighException : public std::exception {
	public:
		const char * what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char * what(void) const throw();
	};
	class NoSignException : public std::exception {
	public:
		const char * what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm &form);

#endif
