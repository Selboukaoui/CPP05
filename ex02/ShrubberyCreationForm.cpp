#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other)
: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return ;
    }

    outfile << "               ,@@@@@@@,\n" ;
    outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
    outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
    outfile << "       |o|        | |         | |\n";
    outfile << "       |.|        | |         | |\n";
    outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\//.  \\_//__/_\n";

    outfile.close();
    std::cout << "Shrubbery created at " << filename << std::endl;
}