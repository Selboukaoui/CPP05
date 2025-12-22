#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
:name("default"), grade(1){}

Bureaucrat::Bureaucrat(std::string name, int grade)
:name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name(other.name)
{
	grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){}


std::string Bureaucrat::getName() const
{return (name);}


int Bureaucrat::getGrade() const
{return this->grade;}


const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "The grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "The grade is too high";
}

void Bureaucrat::incrGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream&  operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return os;
}

// ex01

void Bureaucrat::signForm(Form& _form)
{
    try {
        _form.beSigned(*this);
        std::cout << this->name << " signed " << _form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        // std::cout << this->name << " couldn't sign " << _form.getName() 
        //           << " because " << e.what() << std::endl;
		std::cout << e.what() << std::endl;
    }
}

