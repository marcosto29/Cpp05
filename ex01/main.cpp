#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    Bureaucrat b(
        "marcosto",
        11
    );
    Form f(
        "carta de renuncia",
        10,
        100
    );
    b.signForm(f);
    b.incrementGrade();
    b.signForm(f);

    return 0;
}