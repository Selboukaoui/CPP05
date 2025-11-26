#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat boy;

	boy.setName("ALPHA");

	std::cout << boy << std::endl;

	boy.incrGrade();
	std::cout << boy << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat girl(boy);
	
	
	std::cout << girl << std::endl;

	girl.setName("المجهولة هه");
	
	std::cout << girl << std::endl;

	girl.decrGrade();
	std::cout << girl << std::endl;

	try{
		girl.decrGrade();
	}
	catch (std::exception& e){
		
		std::cout << e.what() << std::endl;
	}
	std::cout << girl << std::endl;
}
