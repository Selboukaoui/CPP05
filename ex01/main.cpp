

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
    // Out of range 
    try {
        Form A("bad grade", 0, 1);
    }
    catch (std::exception &e)
    {
        std:: cout << e.what() << std::endl;
    }

    try {
        Form A("bad grade", 151, 1);
     }
     catch (std::exception &e)
     {
        std:: cout << e.what() << std::endl;
     }

    try {
        Form A("bad grade", 1, 151);
     }
     catch (std::exception &e)
     {
        std:: cout << e.what() << std::endl;
     }

     try {
        Form A("bad grade", 1, 0);
     }
     catch (std::exception &e)
     {
        std:: cout << e.what() << std::endl;
     }


    Bureaucrat K("kamo", 1);
    Bureaucrat D("dojo", 150);

    Form Bac("Baccalaureate", 2, 2);

    std::cout << Bac << std::endl;
    // ---- should sign

    K.signForm(Bac);


    // ---- already signed 
    std::cout << Bac << std::endl;

    K.signForm(Bac);

    //  ---- Low grade 
    Form certif("certificate", 1, 2);
    
    std::cout << certif << std::endl;
    
    D.signForm(certif);

    // --- copy form
    std::cout << " \n===== ORIGINAL ==== \n";
    std::cout << Bac << std::endl;
    Form copy(Bac);
    std::cout << " \n===== COPY ==== \n";
    std::cout << copy << std::endl;

    // -- copy form

    std::cout << " \n===== ORIGINAL ==== \n";
    std::cout << Bac << std::endl;
    Form copy2 = Bac;
    std::cout << " \n===== COPY ==== \n";
    std::cout << copy2 << std::endl;

}
