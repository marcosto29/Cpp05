#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
AForm::AForm() : _name(""), _signedRequired(0), _executeRequired(0)
{
	_signed = false;
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), 
_signedRequired(copy.getSignedGradeRequired()), 
_executeRequired(copy.getExecuteGradeRequired())
{
	_signed = false;
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(std::string name, std::string target, int signRequired, int executeRequired) : _name(name),
_signedRequired(signRequired), 
_executeRequired(executeRequired)
{
	_target = target;
	_signed = false;
	if (signRequired > 150 || executeRequired > 150)
		throw AForm::GradeTooLowException();
	if (signRequired < 1 || executeRequired < 1)
		throw AForm::GradeTooHighException();
	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
}


// Destructor
AForm::~AForm()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
AForm & AForm::operator=(const AForm &that)
{
	if (this != &that)
		_signed = that._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &out, AForm &f)
{
    out << "Form: " << f.getName() << " "
					<< f.getSigned() << " "
					<< f.getSignedGradeRequired() << " "
					<< f.getExecuteGradeRequired() << ".\n";
	return out;
}


// Getters / Setters
std::string AForm::getName() const
{
	return _name;
}
std::string AForm::getTarget() const
{
	return _target;
}
bool AForm::getSigned() const
{
	return _signed;
}
int AForm::getSignedGradeRequired() const
{
	return _signedRequired;
}
int AForm::getExecuteGradeRequired() const
{
	return _executeRequired;
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > getSignedGradeRequired())
		throw AForm::GradeTooLowException();

	_signed = true;	
}

void	AForm::checkRequirements(const Bureaucrat& b) const
{
	if (getSigned() == false)
		throw AForm::NotSignedException();
	if (b.getGrade() > getSignedGradeRequired())
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const& executor) const
{
	checkRequirements(executor);
	executeAction();
}