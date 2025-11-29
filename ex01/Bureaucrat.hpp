
#pragma once

#include <iostream>
#include <string>

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
		void signForm();

		
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() override;
		};
};
	
std::ostream& operator<<(std::ostream &os, const Bureaucrat &other);
