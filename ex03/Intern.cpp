#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            for (int j = 0; j < 3; j++)
                if (i != j) delete forms[j];
            return forms[i];
        }
    }

    for (int i = 0; i < 3; i++)
        delete forms[i];

    throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw()
{
    return "Intern cannot create unknown form!";
}
