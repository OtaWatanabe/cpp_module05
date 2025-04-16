#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <cstdlib>
# include <ctime>


class RobotomyRequestForm : public AForm {
private:
	static const int	SIGN_GRADE = 72;
	static const int	EXECUTE_GRADE = 45;
	static const std::string	NAME;
	const std::string	target_;

public:
	RobotomyRequestForm(std::string target="target");
	RobotomyRequestForm(const RobotomyRequestForm &form);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
	void	execute(Bureaucrat const & executor) const;
};

#endif
