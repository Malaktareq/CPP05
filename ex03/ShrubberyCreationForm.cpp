#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::ofstream outfile;
    std::string filename = _target + "_shrubbery";
    outfile.open(filename.c_str(),std::ios::out);
    if (!outfile)
    {
        std::cerr << "Error creating file: " << filename << std::endl;
        return;
    }


    int i = 12;
    int l = i /2;
    for ( ;i > 5; i--)
    {
        for ( int j =0 ; j < l ; j++)
        {
            outfile << " " ;
        }
        l--;
        for (int k = 0; k < (12 - i) * 2 + 1; k++)
        {
            outfile << "*" ;
        }
        outfile << std::endl;
    }
    outfile << "     ||    " << std::endl;
    outfile << "     ||    " << std::endl;
}

