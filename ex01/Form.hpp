#pragma once
#include <string>
#include "Bureaucrat.hpp"

class Form 
{
    private:
        std::string const   _name;
        bool                _signed;
        const int           reqGradeToSign;
        const int           reqGradeToExec;

    public:
        Form();
        Form(std::string name, bool sign, const int reqTosign, const int reqToExec);
        Form(Form& other);
        Form& operator=(Form& other);
        ~Form();

        std::string     getName() const;
        bool            isSigned();
        int             requiredGradeToSign();
        int             requiredGradeToExecute();
        void            beSigned(Bureaucrat &r);
        
        
        class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() override;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() override;
		};
        class NotSignedException : public std::exception 
        {
            public:
                const char *what() const throw() override;
        };

};

std::ostream& operator<<(std::ostream &os, Form &other);