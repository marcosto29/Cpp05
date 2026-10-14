#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;
class Form
{
	public:
		// Constructors
		Form();
		Form(const Form &copy);
		Form(std::string name, int signGradeRequired, int executeGradeRequired);
		
		// Destructor
		~Form();
		
		// Operators
		Form & operator=(const Form &assign);
		friend std::ostream &operator<<(std::ostream &out, Form &f);
		
		// Getters / Setters
		std::string getName() const;
		bool getSigned() const;
		int getSignedGradeRequired() const;
		int getExecuteGradeRequired() const;

		//functions
		void beSigned(const Bureaucrat& b);

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
		
	private:
		const std::string _name;
		const int _signedRequired;
		const int _executeRequired;
		bool _signed;
		
};

#endif