#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    srand(time(NULL));
    std::cout << "====== BUREAUCRATS ======\n";
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 140);
    Bureaucrat intern("Intern", 150);

    std::cout << boss << std::endl;
    std::cout << worker << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n====== CREATE FORMS ======\n";
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n====== SIGNING TESTS ======\n";
    intern.signForm(shrub);   // fail
    worker.signForm(shrub);   // success

    worker.signForm(robot);   // fail
    boss.signForm(robot);     // success

    boss.signForm(pardon);    // success

    std::cout << "\n====== EXECUTION TESTS ======\n";

    try
    {
        std::cout << "Intern tries executing shrubbery\n";
        shrub.execute(intern);    // fail execute grade
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Worker executes shrubbery\n";
        shrub.execute(worker);    // success → creates file
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Boss executes robotomy multiple times\n";
        robot.execute(boss);  // 50% success
        robot.execute(boss);
        robot.execute(boss);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Boss executes pardon\n";
        pardon.execute(boss);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n====== UNSIGNED FORM TEST ======\n";
    try
    {
        ShrubberyCreationForm test("garden");
        boss.executeForm(test);   // should throw (not signed)
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
