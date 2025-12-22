#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern stagiaire;
    Bureaucrat boss("Boss", 1);

    try {
     
        AForm* f1 = stagiaire.makeForm("shrubbery creation", "Home");
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;

        std::cout << "\n\n";

        AForm* f2 = stagiaire.makeForm("robotomy request", "Bemo");
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;


        std::cout << "\n\n";


        AForm* f3 = stagiaire.makeForm("presidential pardon", "7bicha");
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;

        std::cout << "\n\n";


        // --- Unknown form ---
        AForm* f4 = stagiaire.makeForm("unknown form", "Target");
        delete f4;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}