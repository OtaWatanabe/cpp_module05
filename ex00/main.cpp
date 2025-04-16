#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat bure1("bure1", 1);
	Bureaucrat bure2("bure2", 150);
	Bureaucrat bure3(bure1);
	Bureaucrat bure4(bure2);
	Bureaucrat anonymous;

	std::cout << bure1 << std::endl;
	std::cout << bure2 << std::endl;
	std::cout << bure3 << std::endl;
	std::cout << bure4 << std::endl;
	std::cout << anonymous << std::endl;
	anonymous = bure1;
	std::cout << anonymous << std::endl;
	try {
		bure1.incrementGrade();
		std::cout << "bure1 increment success" << std::endl;
	}
	catch(std::exception & e) {
		std::cout << "bure1 increment: " << e.what() << std::endl;
	}
	try {
		bure2.decrementGrade();
		std::cout << "bure2 decrement success" << std::endl;
	}
	catch(std::exception & e) {
		std::cout << "bure2 decrement: " << e.what() << std::endl;
	}
	try {
		bure3.decrementGrade();
		std::cout << "bure3 decrement success" << std::endl;
	}
	catch(std::exception & e) {
		std::cout << "bure3 decrement: " << e.what() << std::endl;
	}
	try {
		bure4.incrementGrade();
		std::cout << "bure4 increment success" << std::endl;
	}
	catch(std::exception & e) {
		std::cout << "bure4 increment: " << e.what() << std::endl;
	}
	std::cout << "grade: " << std::endl;
	std::cout << bure1.getName() << ": " << bure1.getGrade() << std::endl;
	std::cout << bure2.getName() << ": " << bure2.getGrade() << std::endl;
	std::cout << bure3.getName() << ": " << bure3.getGrade() << std::endl;
	std::cout << bure4.getName() << ": " << bure4.getGrade() << std::endl;
	std::cout << bure1 << std::endl;
	std::cout << bure2 << std::endl;
	std::cout << bure3 << std::endl;
	std::cout << bure4 << std::endl;
	try {
		Bureaucrat low("low", 151);
		std::cout << "low constructed successfully" << std::endl;
	}
	catch(std::exception & e) {
		std::cout << "constructor: " << e.what() << std::endl;
	}
	try {
		Bureaucrat high("high", 0);
		std::cout << "high constructed successfully" << std::endl;
	}
	catch(std::exception & e) {
		std::cout << "constructor: " << e.what() << std::endl;
	}
}
