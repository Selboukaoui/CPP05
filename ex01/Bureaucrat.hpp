
#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

class Bureaucrat {

	private :
		std::string name;
		int grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat& other);
		Bureaucrat& operator=(Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void setName(std::string _name);
		void incrGrade();
		void decrGrade();
		void signForm(Form& _form);

		
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};
	
std::ostream& operator<<(std::ostream &os, const Bureaucrat &other);
