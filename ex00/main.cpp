#include "Bureaucrat.hpp"

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;
    Bureaucrat burocrata("burocrata", 2);
    burocrata.incrementGrade();
    try{
        burocrata.incrementGrade();
        std::cout << burocrata << "\n";
    }catch(std::exception & e){
        std::cout << e.what();
    }
    burocrata.decrementGrade();
    std::cout << burocrata << "\n";
    burocrata.incrementGrade();
    std::cout << burocrata << "\n";
    //como no está controlado el try catch 
    //la función throweara una exepción que no será recogida y dara core dumped
    burocrata.incrementGrade();
    std::cout << burocrata << "\n";

    Bureaucrat burocrata2("nombre2", 1);
    burocrata2 = burocrata;
    std::cout << burocrata2 << "\n";
    return 0;
}