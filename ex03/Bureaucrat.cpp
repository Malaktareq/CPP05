#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    _name = "default";
    _grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    this->_name = name;
    this->_grade = grade;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        _name = other._name;
        _grade = other._grade;
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    _name = other._name;
    _grade = other._grade;
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}
void Bureaucrat::increment(int amount)
{
    if(this->_grade - amount < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->_grade -= amount;
}

void Bureaucrat::decrement(int amount)
{
    if(this->_grade + amount > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade += amount;
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too LOW!";
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too HIGH!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." ;
    return out;
}

void Bureaucrat::signForm(AForm& AForm)
{
    try
    {
        AForm.beSigned(*this);
    }
    catch(std::exception& e)
    {
        std::cout << _name << " cannot sign " << AForm.getName() << " because " << e.what() << std::endl;
        return ;
    }
    std::cout << _name << " signs " << AForm.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}