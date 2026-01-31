#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "====== CREATE BUREAUCRATS ======\n";
    try
    {
        Bureaucrat a("Alice", 2);
        Bureaucrat b("Bob", 140);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << "\n====== CREATE FORMS ======\n";

        Form taxForm("Tax Form", 50, 25);
        Form topSecret("Top Secret", 1, 1);

        std::cout << taxForm << std::endl;
        std::cout << topSecret << std::endl;

        std::cout << "\n====== SIGNING TESTS ======\n";

        b.signForm(taxForm);     // Bob grade 140 → should FAIL
        a.signForm(taxForm);     // Alice grade 2 → should SUCCEED

        std::cout << "\nAfter signing taxForm:\n";
        std::cout << taxForm << std::endl;

        std::cout << "\nTrying to sign Top Secret form:\n";
        a.signForm(topSecret);   // Alice grade 2 → should FAIL (needs 1)

    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n====== BAD FORM TEST ======\n";
    try
    {
        Form bad("Bad Form", 0, 10);  // invalid grade → exception
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n====== BAD BUREAUCRAT TEST ======\n";
    try
    {
        Bureaucrat c("Crazy", 151); // invalid grade → exception
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
