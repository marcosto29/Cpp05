#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;
class AForm
{
	public:
		// Constructors
		AForm();
		AForm(const AForm &copy);
		AForm(std::string name, std::string target, int signGradeRequired, int executeGradeRequired);

		// Destructor
		virtual ~AForm();

		// Operators
		AForm & operator=(const AForm &assign);
		friend std::ostream &operator<<(std::ostream &out, AForm &f);

		// Getters / Setters
		std::string getName() const;
		std::string getTarget() const;
		bool getSigned() const;
		int getSignedGradeRequired() const;
		int	getExecuteGradeRequired() const;

		//functions
		void			beSigned(const Bureaucrat& b);
		void			checkRequirements(const Bureaucrat& b) const;
		void			execute(Bureaucrat const & executor) const;
		virtual void	executeAction() const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade too high!\n";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade too low!\n";
				}
		};

		class NotSignedException : public std::exception {
			public:
				const char* what() const throw() {
					return "Form not signed!\n";
				}
		};

	private:
		std::string _name;
		bool _signed;
		int _signedRequired;
		int _executeRequired;
		std::string _target;
};

#endif