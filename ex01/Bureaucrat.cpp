#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name("default")
{
	_grade = 150;
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	_grade = copy.getGrade();
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
    }
	if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
    }
	_grade = grade;
	std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &that)
{
	if (this != &that)
		_grade = that._grade;
	return *this;
}

std::ostream & operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}

// Getters / Setters
std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

//functions
void	Bureaucrat::incrementGrade()
{
	if (Bureaucrat::_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
    }
	Bureaucrat::_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (Bureaucrat::_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
    }
	Bureaucrat::_grade += 1;
}

void	Bureaucrat::signForm(Form& f)
{
	try{
		f.beSigned(*this);
		std::cout << getName() << " signed " 
					<< f.getName() << "\n";
	}catch(std::exception & e){
		std::cout << getName() << " couldn’t sign " 
					<< f.getName() << " because "
					<< e.what() << "\n";
	}
}