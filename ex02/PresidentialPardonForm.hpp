#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	static const int	SIGN_GRADE = 25;
	static const int	EXECUTE_GRADE = 5;
	static const std::string	NAME;
	const std::string	target_;

public:
	PresidentialPardonForm(std::string target="target");
	PresidentialPardonForm(const PresidentialPardonForm& form);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
	void	execute(Bureaucrat const & executor) const;
};

#endif
