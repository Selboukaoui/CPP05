#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat boss("Boss", 10);

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

    try
    {
        ShrubberyCreationForm shrub("office");
        Bureaucrat ceo("CEO", 1);

        ceo.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception (not signed): " << e.what() << std::endl;
    }

    std::cout << "\n -- Couldn't sign Grade is too low -- \n" << std::endl;
    try
    {
        RobotomyRequestForm robot("Emo");
        Bureaucrat stagiaire("stagiaire", 150);

        stagiaire.signForm(robot);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception (sign grade too low): " << e.what() << std::endl;
    }

    std::cout << "\n -- couldn't execute Grade is too low -- \n" << std::endl;
    try
    {
        PresidentialPardonForm pardon("Ford Prefect");
        Bureaucrat boss("Boss", 1);
        Bureaucrat low("Low", 150);

        boss.signForm(pardon);
        low.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception (execute grade too low): " << e.what() << std::endl;
    }

    return 0;
}
