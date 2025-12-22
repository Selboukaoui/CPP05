#pragma once
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm 
{
    private:
        const std::string    _name;
        bool                _signed;
        const int           reqGradeToSign;
        const int           reqGradeToExec;
        virtual void executeAction() const = 0;
    public:
        AForm();
        AForm(std::string name, const int reqTosign, const int reqToExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        std::string     getName() const;
        bool            isSigned() const; 
        int             requiredGradeToSign() const;
        int             requiredGradeToExecute() const;
        void            beSigned(const  Bureaucrat &r);
        
        
        class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
        class NotSignedException : public std::exception 
        {
            public:
                std::string err_msg;
                NotSignedException(const std::string& BurName, const std::string& FormName, const std::string& reason);
                const char *what() const throw();
                virtual ~NotSignedException() throw();
        };

        // ex02
        class FormNotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowToExecuteException : public std::exception {
            public:
                const char *what() const throw();
        };
        virtual void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream &os, const AForm &other);

