#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
private:
	static const int	SIGN_GRADE = 145;
	static const int	EXECUTE_GRADE = 137;
	static const std::string	NAME;
	const std::string	target_;
public:
	ShrubberyCreationForm(std::string target="target");
	ShrubberyCreationForm(const ShrubberyCreationForm& shrub_form);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shurub_form);
	void	execute(Bureaucrat const & executor) const;
};

#endif
