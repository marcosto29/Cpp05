#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form() : _name(""), _signedRequired(0), _executeRequired(0)
{
	_signed = false;
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName()), 
_signedRequired(copy.getSignedGradeRequired()), 
_executeRequired(copy.getExecuteGradeRequired())
{
	_signed = false;
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string name, int signRequired, int executeRequired) : _name(name), 	
_signedRequired(signRequired), 
_executeRequired(executeRequired)
{
	_signed = false;
	if (signRequired > 150 || executeRequired > 150)
		throw Form::GradeTooLowException();
	if (signRequired < 1 || executeRequired < 1)
		throw Form::GradeTooHighException();
	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &that)
{
	if (this != &that)
		_signed = that._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &out, Form &f)
{
    out << "Form: " << f.getName() << " "
					<< f.getSigned() << " "
					<< f.getSignedGradeRequired() << " "
					<< f.getExecuteGradeRequired() << ".\n";
	return out;
}


// Getters / Setters
std::string Form::getName() const
{
	return _name;
}
bool Form::getSigned() const
{
	return _signed;
}
int Form::getSignedGradeRequired() const
{
	return _signedRequired;
}
int Form::getExecuteGradeRequired() const
{
	return _executeRequired;
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > getSignedGradeRequired())
		throw Form::GradeTooLowException();

	_signed = true;	
}