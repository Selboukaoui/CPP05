#pragma once
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;
        void executeAction() const;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const & target);
        RobotomyRequestForm(RobotomyRequestForm const & other);
        RobotomyRequestForm& operator=(RobotomyRequestForm const & other);
        ~RobotomyRequestForm();

        std::string getTarget() const;
};