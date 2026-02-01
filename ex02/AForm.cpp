#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(0), _signGrade(150), _executeGrade(150)
{

}
AForm::AForm(std::string const name, int const signGrade, int const executeGrade) :
 _name(name), _isSigned(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : 
_name(other._name), _isSigned(0), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{

}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;

    }
    return (*this);
}

AForm::~AForm()
{

}
void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooHighException();
    _isSigned = 1;
}

bool AForm::isSigned() const
{
    return (_isSigned);
}
std::string const AForm::getName() const
{
    return (_name);
}

int AForm::getSignGrade() const
{
    return (_signGrade);
}

int AForm::getExecuteGrade() const
{
    return (_executeGrade);
}

const char* AForm::GradeTooHighException::what() const throw()
{
   return "Form Grade is too HIGH!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form Grade is too LOW!";
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
    out << "Aform Name: " << AForm.getName() << ", Signed: " << (AForm.isSigned() ? "Yes" : "No")
        << ", Sign Grade: " << AForm.getSignGrade() << ", Execute Grade: " << AForm.getExecuteGrade();
    return out;
}


void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
    {
        std::cout << "Form is not signed!" << std::endl;
        return;
    }
    if (executor.getGrade() > this->getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }
}