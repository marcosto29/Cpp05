#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm()
: AForm()
{
	std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: AForm(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("Presidential Pardon", target, 25, 5)
{
	std::cout << "\e[0;33mFields Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &that)
{
	if (this != &that)
		AForm::operator=(that);
	return *this;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}