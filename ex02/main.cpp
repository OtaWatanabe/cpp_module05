#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	Bureaucrat	bure150("low", 150);
	Bureaucrat	bure1("high", 1);
	PresidentialPardonForm	pre1("pre1");
	PresidentialPardonForm	pre2(pre1);
	PresidentialPardonForm	pre3;

	pre3 = pre2;
	std::cout << pre1 << std::endl;
	std::cout << pre2 << std::endl;
	std::cout << pre3 << std::endl;
	try {
		pre1.execute(bure1);
		std::cout << bure1.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure1.getName() << ": execution failed: " << e.what() << std::endl;
	}
	try {
		pre1.execute(bure150);
		std::cout << bure150.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure150.getName() << ": execution failed: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	bure1.signForm(pre1);
	try {
		pre1.execute(bure1);
		std::cout << bure1.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure1.getName() << ": execution failed: " << e.what() << std::endl;
	}
	try {
		pre1.execute(bure150);
		std::cout << bure150.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure150.getName() << ": execution failed: " << e.what() << std::endl;
	}
	bure1.executeForm(pre1);
	bure150.executeForm(pre1);

	std::cout << "\nrobotomy\n" << std::endl;
	RobotomyRequestForm	robo1("robo");
	RobotomyRequestForm	robo2(robo1);
	RobotomyRequestForm	robo3;

	robo3 = robo1;
	std::cout << robo1 << std::endl;
	std::cout << robo2 << std::endl;
	std::cout << robo3 << std::endl;
	try {
		robo1.execute(bure1);
		std::cout << bure1.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure1.getName() << ": execution failed: " << e.what() << std::endl;
	}
	try {
		robo1.execute(bure150);
		std::cout << bure150.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure150.getName() << ": execution failed: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	bure1.signForm(robo1);
	try {
		robo1.execute(bure1);
		std::cout << bure1.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure1.getName() << ": execution failed: " << e.what() << std::endl;
	}
	try {
		robo1.execute(bure150);
		std::cout << bure150.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure150.getName() << ": execution failed: " << e.what() << std::endl;
	}
	bure1.executeForm(robo1);
	bure150.executeForm(robo1);

	std::cout << "\nshrubberry\n" << std::endl;
	ShrubberyCreationForm	shru1("shru");
	ShrubberyCreationForm	shru2(shru1);
	ShrubberyCreationForm	shru3;

	shru3 = shru1;
	std::cout << shru1 << std::endl;
	std::cout << shru2 << std::endl;
	std::cout << shru3 << std::endl;
	try {
		shru1.execute(bure1);
		std::cout << bure1.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure1.getName() << ": execution failed: " << e.what() << std::endl;
	}
	try {
		shru1.execute(bure150);
		std::cout << bure150.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure150.getName() << ": execution failed: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	bure1.signForm(shru1);
	try {
		shru1.execute(bure1);
		std::cout << bure1.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure1.getName() << ": execution failed: " << e.what() << std::endl;
	}
	try {
		shru1.execute(bure150);
		std::cout << bure150.getName() << ": execution succeeded!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bure150.getName() << ": execution failed: " << e.what() << std::endl;
	}
	bure1.executeForm(shru1);
	bure150.executeForm(shru1);
}
