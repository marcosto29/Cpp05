#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm()
: AForm()
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
: AForm(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("Robotomy Request", target, 72, 45)
{
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &that)
{
	if (this != &that)
		AForm::operator=(that);
	return *this;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "*drilling noises*\n";
	srand(time(NULL));
	if(rand() % 2 == 0)
		std::cout << getTarget() << " has been robotomized successfully\n";
	else
		std::cout << getTarget() << " failed to be robotomized\n";
}