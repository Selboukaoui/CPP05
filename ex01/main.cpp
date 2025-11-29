#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	try{
		Form form("samir", false, 0, 2);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl << std::endl;
	}
	Form bac("baccalurate", false, 90, 100);

	Bureaucrat alpha("ALPHA", 1);
	
	alpha.signForm();


}
