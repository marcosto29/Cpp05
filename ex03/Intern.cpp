#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &that)
{
	(void) that;
	return *this;
}

// Functions
AForm* createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	static const std::string formNames[] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};

	AForm* (*functions[])(const std::string&) = {
		&createPresidential,
		&createRobotomy,
		&createShrubbery
	};

	int i = 0;
	while (i < 3 && formName != formNames[i])
		i++;
	
	if (i < 3)
	{
		std::cout << "Intern creates " << formName << std::endl;
		return functions[i](formTarget);
	}
	else
		std::cout << "No existe ningún formulario con ese nombre" << std::endl;
	return NULL;
}