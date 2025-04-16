#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <exception>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
private:
    const std::string	name_;
	int	grade_;

public:
	Bureaucrat(std::string name="default", int grade=150);
	Bureaucrat(const Bureaucrat& bure);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& bure);
	std::string getName(void) const;
	int	getGrade(void) const;
	void	incrementGrade(void);
	void	decrementGrade(void);
	void	signForm(Form &form) const;
	class GradeTooHighException : public std::exception {
	public:
		const char * what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char * what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bure);

#endif
