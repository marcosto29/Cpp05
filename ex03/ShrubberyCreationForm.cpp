#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm()
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
: AForm(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("Shrubbery Creation", target, 145, 137)
{
	std::cout << "\e[0;33mFields Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &that)
{
	if (this != &that)
		AForm::operator=(that);
	return *this;
}

//function
void ShrubberyCreationForm::executeAction() const
{
	std::string fileName = getTarget() + "_shrubbery.txt";
	std::ofstream outfile (fileName.c_str());
	
	outfile \
    << "                                                    .      \n"
    << "                                         .         ;        \n"
    << "            .              .              ;%     ;;         \n"
    << "              ,           ,                :;%  %;         \n"
    << "               :         ;                   :;%;'     .,         \n"
    << "      ,.        %;     %;            ;        %;'    ,;      \n"
    << "        ;       ;%;  %%;        ,     %;    ;%;    ,%'      \n"
    << "         %;       %;%;      ,  ;       %;  ;%;   ,%;'       \n"
    << "          ;%;      %;        ;%;        % ;%;  ,%;'      \n"
    << "           `%;.     ;%;     %;'         `;%%;.%;'      \n"
    << "            `:;%.    ;%%. %@;        %; ;@%;%'      \n"
    << "               `:%;.  :;bd%;          %;@%;'      \n"
    << "                 `@%:.  :;%.         ;@@%;'         \n"
    << "                   `@%.  `;@%.      ;@@%;               \n"
    << "                     `@%%. `@%%    ;@@%;              \n"
    << "                       ;@%. :@%%  %@@%;             \n"
    << "                         %@bd%%%bd%%:;           \n"
    << "                           #@%%%%%:;;      \n"
    << "                           %@@%%%::;      \n"
    << "                           %@@@%(o);  . '               \n"
    << "                           %@@@o%;:(.,'               \n"
    << "                       `.. %@@@o%::;               \n"
    << "                          `)@@@o%::;               \n"
    << "                           %@@(o)::;              \n"
    << "                          .%@@@@%::;               \n"
    << "                          ;%@@@@%::;.                \n"
    << "                         ;%@@@@%%:;;;.       \n"
    << "                     ...;%@@@@@%%:;;;;,..    Gilo97      \n";

	outfile.close();
}