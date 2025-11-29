#include "Form.hpp"



std::ostream& operator<<(std::ostream &os, Form &other)
{
    std::cout << "============================================="                             << "=" << std::endl;
    std::cout << "=    The Form Name:"<< other.getName()                                     << "=" << std::endl;
    std::cout << "=    Are the Form signed?:"<< other.isSigned()                             << "=" << std::endl;
    std::cout << "=    The Form grade required to sign:"<< other.requiredGradeToSign()       << "=" << std::endl;
    std::cout << "=    The Form grade required to execute:"<< other.requiredGradeToExecute() << "=" << std::endl;
    std::cout << "=============================================" << std::endl;
    return os;
}


Form::Form()
: _name("Default"), _signed(false), reqGradeToSign(1), reqGradeToExec(20) {}

Form::Form(std::string name, bool sign, const int reqTosign, const int reqToExec)
:_name(name), _signed(sign), reqGradeToSign(reqTosign), reqGradeToExec(reqToExec) {

    if (reqGradeToSign < 1 || reqGradeToExec < 1)
        throw Form::GradeTooHighException();
    else if (reqGradeToSign > 150 || reqGradeToExec > 150)
        throw GradeTooLowException();
}


Form::Form(Form& other) 
:_name(other._name), _signed(other._signed), reqGradeToSign(other.reqGradeToSign), reqGradeToExec(other.reqGradeToExec) {}


Form& Form::operator=(Form& other)
{
    if (this != &other)
    {
      _signed = other._signed;
    }
    return *this;
}

Form::~Form(){}



std::string Form::getName() const
{ return _name; }

bool Form::isSigned()
{ return _signed; }

int Form::requiredGradeToSign()
{ return reqGradeToSign; }

int Form::requiredGradeToExecute()
{ return reqGradeToExec; }



const char* Form::GradeTooLowException::what() const throw(){
	return "The grade is too low";
}

const char* Form::GradeTooHighException::what() const throw(){
	return "The grade is too high";
}

const char* Form::NotSignedException::what() const throw(){
	return (" couldn't sign ");
}

void    Form::beSigned(Bureaucrat &r)
{
    if (r.getGrade() > this->reqGradeToSign){
        std::cout << r.getName() << " signed " << this->_name << std::endl;
        this->_signed = true;
    }
    else{
        throw NotSignedException();
    }
}