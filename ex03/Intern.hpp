#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
public:
    Intern(void);
    Intern(const Intern& intern);
    ~Intern();
    Intern & operator=(const Intern& intern);
    AForm*    makeForm(const std::string& formName, const std::string& target) const;
};

#endif
