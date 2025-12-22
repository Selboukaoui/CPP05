#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat hi("High", 160);		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat alpha("Alpha", 1);



	std::cout << alpha << std::endl;

	try{
		alpha.decrGrade();
	}
	catch (std::exception& e){
		
		std::cout << e.what() << std::endl;
	}
	std::cout << alpha << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat hitmana("Hitmana", 150);
	
	
	std::cout << hitmana << std::endl;
	
	hitmana = alpha;

	std::cout << hitmana << std::endl;

	try{
		hitmana.decrGrade();
	}
	catch (std::exception& e){
		
		std::cout << e.what() << std::endl;
	}

	std::cout << hitmana << std::endl;

	try{
		hitmana.decrGrade();
	}
	catch (std::exception& e){
		
		std::cout << e.what() << std::endl;
	}

	std::cout << hitmana << std::endl;
}
