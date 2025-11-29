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

	Bureaucrat alpha;

	alpha.setName("ALPHA");

	std::cout << alpha << std::endl;

	alpha.incrGrade();
	std::cout << alpha << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat hitmana(alpha);
	
	
	std::cout << hitmana << std::endl;

	hitmana.setName("HITMANA");
	
	std::cout << hitmana << std::endl;

	hitmana.decrGrade();
	std::cout << hitmana << std::endl;

	try{
		hitmana.decrGrade();
	}
	catch (std::exception& e){
		
		std::cout << e.what() << std::endl;
	}
	std::cout << hitmana << std::endl;
}
