#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);

        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Bemo");
        PresidentialPardonForm pardon("Samir");

        boss.signForm(shrub);
        boss.executeForm(shrub);

        std::cout << "\n" << std::endl;

        boss.signForm(robot);
        boss.executeForm(robot);

        std::cout << "\n" << std::endl;


        boss.signForm(pardon);
        boss.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n -- Form is not signed -- \n" << std::endl;


        ShrubberyCreationForm shrub("office");
        Bureaucrat ceo("CEO", 1);

        ceo.executeForm(shrub);


    std::cout << "\n -- Couldn't sign Grade is too low -- \n" << std::endl;

        RobotomyRequestForm robot("Emo");
        Bureaucrat stagiaire("stagiaire", 150);

        stagiaire.signForm(robot);


    std::cout << "\n -- couldn't execute Grade is too low -- \n" << std::endl;

        PresidentialPardonForm pardon("X");
        Bureaucrat boss("Boss", 1);
        Bureaucrat low("Low", 150);

        boss.signForm(pardon);
        low.executeForm(pardon);

    return 0;
}
