#include "ShrubberyCreationForm.hpp"

const std::string	ShrubberyCreationForm::NAME = "shrubbery";

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm(NAME, false, SIGN_GRADE, EXECUTE_GRADE) , target_(target) {
	std::cout << "ShrubberyCreationForm: default or assignment constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form), target_(form.target_) {
	std::cout << "ShrubberyCreationForm: copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
	AForm::operator=(form);
	std::cout << "ShrubberyCreationForm: copy assignment called" << std::endl;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	checkExecutable(executor);
	std::ofstream	writeFile(target_ + "_shrubbery");
	if (writeFile.fail()) {
		std::cerr << "failed to open file " << target_ + "_shrubbery" << std::endl;
		return ;
	}
	std::string tree =
        "       /\\\n"
        "      /  \\\n"
        "     /    \\\n"
        "    /      \\\n"
        "   /________\\\n"
        "      ||||\n"
        "      ||||\n";
	writeFile << tree;
	writeFile.close();
}
