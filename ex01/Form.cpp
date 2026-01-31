#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(0), _signGrade(150), _executeGrade(150)
{

}
Form::Form(std::string const name, int const signGrade, int const executeGrade) :
 _name(name), _isSigned(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : 
_name(other._name), _isSigned(0), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{

}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;

    }
    return (*this);
}

Form::~Form()
{

}
void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw Form::GradeTooHighException();
    _isSigned = 1;
}

bool Form::isSigned() const
{
    return (_isSigned);
}
std::string const Form::getName() const
{
    return (_name);
}

int Form::getSignGrade() const
{
    return (_signGrade);
}

int Form::getExecuteGrade() const
{
    return (_executeGrade);
}

const char* Form::GradeTooHighException::what() const throw()
{
   return "Form Grade is too HIGH!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade is too LOW!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form Name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
        << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return out;
}


