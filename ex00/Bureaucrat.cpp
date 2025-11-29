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

Bureaucrat::Bureaucrat(Bureaucrat& other)
{
	name = other.name;
	grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
	if (this != &other)
	{
		name = other.name;
		grade = other.grade;
	}
	return other;
}

Bureaucrat::~Bureaucrat(){}



std::string Bureaucrat::getName() const
{return (name);}

void Bureaucrat::setName(std::string _name)
{name = _name;};

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
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}


void Bureaucrat::decrGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

std::ostream&  operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return os;
}