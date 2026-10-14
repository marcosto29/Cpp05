#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm(std::string target);

		// Destructor
		~ShrubberyCreationForm();

		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);

	private:
		//function
		void executeAction() const;

};

#endif