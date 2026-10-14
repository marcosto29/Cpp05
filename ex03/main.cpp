#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    Intern *i = new Intern();

    AForm *presidentialForm = i->makeForm("PresidentialPardonForm", "marcosto");
    
    Bureaucrat *b = new Bureaucrat("marcosto", 1);

    presidentialForm->beSigned(*b);
    presidentialForm->execute(*b);

    delete i;
    delete b;
    delete presidentialForm;
}