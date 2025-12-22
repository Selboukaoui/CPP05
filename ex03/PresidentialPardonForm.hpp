#pragma once
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;
        void executeAction() const;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const & target);
        PresidentialPardonForm(PresidentialPardonForm const & other);
        PresidentialPardonForm& operator=(PresidentialPardonForm const & other);
        ~PresidentialPardonForm();

        std::string getTarget() const;
};