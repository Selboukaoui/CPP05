#pragma once
#include <string>

class Bureaucrat;

class Form 
{
    private:
        std::string const   _name;
        bool                _signed;
        const int           reqGradeToSign;
        const int           reqGradeToExec;

    public:
        Form();
        Form(std::string name, const int reqTosign, const int reqToExec);
        Form(Form& other);
        Form& operator=(Form& other);
        ~Form();

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
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &os,  Form &other);