#include "Intern.hpp"

Intern::Intern()
{

}
Intern::Intern(const Intern& other)
{
    (void)other;
}
Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{

}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i])
        {
            switch (i)
            {
                case 0:
                    std::cout << "Intern creates " << formName << " form." << std::endl;
                    return new ShrubberyCreationForm(target);
                case 1:
                    std::cout << "Intern creates " << formName << " form." << std::endl;
                    return new RobotomyRequestForm(target);
                case 2:
                    std::cout << "Intern creates " << formName << " form." << std::endl;
                    return new PresidentialPardonForm(target);
            }
        }
    }
    std::cout << "Intern could not find the form: " << formName << std::endl;
    return NULL;
}