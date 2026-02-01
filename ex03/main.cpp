#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    srand(time(NULL));
    std::cout << "====== BUREAUCRATS ======\n";
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 50);

    std::cout << boss << std::endl;
    std::cout << worker << std::endl;

    std::cout << "\n====== CREATE INTERN ======\n";
    Intern someIntern;

    std::cout << "\n====== INTERN MAKES FORMS ======\n";

    AForm* form1 = someIntern.makeForm("shrubbery creation", "home");
    AForm* form2 = someIntern.makeForm("robotomy request", "Bender");
    AForm* form3 = someIntern.makeForm("presidential pardon", "Marvin");
    AForm* form4 = someIntern.makeForm("unknown form", "Test"); 

    std::cout << "\n====== SIGN AND EXECUTE FORMS ======\n";

    if (form1)
    {
        worker.signForm(*form1);
        try { form1->execute(worker); }
        catch (std::exception &e) { std::cout << e.what() << std::endl; }
    }

    if (form2)
    {
        boss.signForm(*form2);
        try { form2->execute(boss); }
        catch (std::exception &e) { std::cout << e.what() << std::endl; }
    }

    if (form3)
    {
        boss.signForm(*form3);
        try { form3->execute(boss); }
        catch (std::exception &e) { std::cout << e.what() << std::endl; }
    }

    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}
