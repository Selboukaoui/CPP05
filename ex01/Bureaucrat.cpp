#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
:name("default"), grade(1){}

Bureaucrat::Bureaucrat(std::string name, int grade)
:name(name), grade(grade){}

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
	return "The grade can't be less than 1";
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "The grade can't be more than 150";
}


void Bureaucrat::incrGrade()
{
	if (grade == 150)
		throw GradeTooHighException();
	grade++;
}


void Bureaucrat::decrGrade()
{
	if (grade == 1)
		throw GradeTooLowException();
	grade--;
}

std::ostream&  operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return os;
}