#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class AForm;
class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(std::string name, int grade);
		
		// Destructor
		~Bureaucrat();
		
		// Operators
		Bureaucrat &operator=(const Bureaucrat &assign);
		friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
		
		// Getters / Setters
		std::string getName() const;
		int			getGrade() const;

		//functions
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm& f) const;
		void		executeForm(AForm const & form) const;
		
	private:
		const std::string	_name;
		int					_grade;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade too high!\n";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade too low!";
			}
	};
};

#endif