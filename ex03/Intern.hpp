#pragma once
 
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <exception>

class Intern
{
public:
    Intern();
    ~Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);

    AForm* makeForm(const std::string &formName, const std::string &target) const;

    class UnknownFormException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};

