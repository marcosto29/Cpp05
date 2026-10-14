# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    Bureaucrat b("marcosto", 1);
    ShrubberyCreationForm s("archivo");
    PresidentialPardonForm p("marcosto");
    RobotomyRequestForm r("marcosto");

    b.signForm(s);
    b.executeForm(s);

    b.signForm(p);
    b.executeForm(p);

    b.signForm(r);
    b.executeForm(r);
}