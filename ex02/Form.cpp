#include "Form.hpp"
#include "Bureaucrat.hpp"


std::ostream& operator<<(std::ostream &os, Form &other)
{
    os << "============================================================\n"                        
     << "=    The Form Name:                       "<< other.getName()  << "\n"                             
     << "=    Are the Form signed?:                "<< other.isSigned()     << "\n"                         
     << "=    The Form grade required to sign:     "<< other.requiredGradeToSign()    << "\n"               
     << "=    The Form grade required to execute:  "<< other.requiredGradeToExecute()   << "\n"            
     << "============================================================\n";
    return os;
}


Form::Form()
: _name("Default"), _signed(false), reqGradeToSign(1), reqGradeToExec(20) {}

Form::Form(std::string name, const int reqTosign, const int reqToExec)
:_name(name), _signed(false), reqGradeToSign(reqTosign), reqGradeToExec(reqToExec) {

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
Form::NotSignedException::~NotSignedException() throw(){};


std::string Form::getName() const
{ return _name; }

bool Form::isSigned() const
{ return _signed; }

int Form::requiredGradeToSign() const
{ return reqGradeToSign; }

int Form::requiredGradeToExecute() const
{ return reqGradeToExec; }



const char* Form::GradeTooLowException::what() const throw(){
	return "The grade is too low";
}

const char* Form::GradeTooHighException::what() const throw(){
	return "The grade is too high";
}

Form::NotSignedException::NotSignedException(const std::string& BurName, const std::string& FormName, const std::string& reason)
{
    err_msg = BurName + " Couldn't sign " + FormName + reason;
}


const char* Form::NotSignedException::what() const throw(){
	return (err_msg.c_str());
}

void    Form::beSigned(const Bureaucrat &r)
{
    if (r.getGrade() <= reqGradeToSign && !_signed){
        std::cout << r.getName() << " signed " << _name << std::endl;
        _signed = true;
    }
    else if (_signed == true)
    {
        throw NotSignedException(r.getName(), this->getName(), " because it's alreay signed ");
    }
    else{
        throw NotSignedException(r.getName(), this->getName(), " because their Grade is too low ");
    }
}