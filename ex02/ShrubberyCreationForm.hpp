#pragma once
#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
        void executeAction() const;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const &other);
        ~ShrubberyCreationForm();

        std::string getTarget() const;
};