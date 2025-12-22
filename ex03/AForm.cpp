#include "AForm.hpp"
#include "Bureaucrat.hpp"


std::ostream& operator<<(std::ostream &os, const AForm &other)
{
    os << "============================================================\n"                        
     << "=    The Form Name:                       "<< other.getName()  << "\n"                             
     << "=    Are the Form signed?:                "<< other.isSigned()     << "\n"                         
     << "=    The Form grade required to sign:     "<< other.requiredGradeToSign()    << "\n"               
     << "=    The Form grade required to execute:  "<< other.requiredGradeToExecute()   << "\n"            
     << "============================================================\n";
    return os;
}


AForm::AForm()
: _name("Default"), _signed(false), reqGradeToSign(1), reqGradeToExec(20) {}

AForm::AForm(std::string name, const int reqTosign, const int reqToExec)
:_name(name), _signed(false), reqGradeToSign(reqTosign), reqGradeToExec(reqToExec) {

    if (reqGradeToSign < 1 || reqGradeToExec < 1)
        throw AForm::GradeTooHighException();
    else if (reqGradeToSign > 150 || reqGradeToExec > 150)
        throw GradeTooLowException();
}


AForm::AForm(const AForm& other) 
:_name(other._name), _signed(other._signed), reqGradeToSign(other.reqGradeToSign), reqGradeToExec(other.reqGradeToExec) {}


AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
      _signed = other._signed;
    }
    return *this;
}

AForm::~AForm(){}
AForm::NotSignedException::~NotSignedException() throw(){};


std::string AForm::getName() const
{ return _name; }

bool AForm::isSigned() const
{ return _signed; }

int AForm::requiredGradeToSign() const
{ return reqGradeToSign; }

int AForm::requiredGradeToExecute() const
{ return reqGradeToExec; }



const char* AForm::GradeTooLowException::what() const throw(){
	return "The grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "The grade is too high";
}

AForm::NotSignedException::NotSignedException(const std::string& BurName, const std::string& FormName, const std::string& reason)
{
    err_msg = BurName + " couldn't sign " + FormName + " because " + reason;
}


const char* AForm::NotSignedException::what() const throw(){
	return (err_msg.c_str());
}

void AForm::beSigned(const Bureaucrat &r)
{
    if (_signed)
        throw NotSignedException(r.getName(), this->getName(), "it's already signed");
    
    if (r.getGrade() > reqGradeToSign)
        throw NotSignedException(r.getName(), this->getName(), "their grade is too low");
    
    _signed = true;
}


//ex02

const char* AForm::FormNotSignedException::what() const throw(){
    return "Form is not signed";
}

const char* AForm::GradeTooLowToExecuteException::what() const throw(){
    return "Bureaucrat grade is too low to execute this form";
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    
    if (executor.getGrade() > reqGradeToExec)
        throw GradeTooLowToExecuteException();
    
    executeAction();
}