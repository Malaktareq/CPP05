#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== CONSTRUCTOR TESTS =====" << std::endl;

    try {
        Bureaucrat a("Alice", 75);
        std::cout << a << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 0);
    } catch (std::exception &e) {
        std::cout << "Bob error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Charlie", 151);
    } catch (std::exception &e) {
        std::cout << "Charlie error: " << e.what() << std::endl;
    }

    std::cout << "\n===== INCREMENT TESTS =====" << std::endl;

    try {
        Bureaucrat d("David", 50);
        std::cout << "Before: " << d << std::endl;
        d.increment(10);
        std::cout << "After:  " << d << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat e("Emma", 5);
        std::cout << "Before: " << e << std::endl;
        e.increment(4);  // to 1
        std::cout << "After:  " << e << std::endl;
        e.increment(1);  // should throw
    } catch (std::exception &e) {
        std::cout << "Emma error: " << e.what() << std::endl;
    }

    std::cout << "\n===== DECREMENT TESTS =====" << std::endl;

    try {
        Bureaucrat f("Frank", 100);
        std::cout << "Before: " << f << std::endl;
        f.decrement(20);
        std::cout << "After:  " << f << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat g("Hanna", 140);
        std::cout << "Before: " << g << std::endl;
        g.decrement(10); // to 150
        std::cout << "After:  " << g << std::endl;
        g.decrement(1);  // should throw
    } catch (std::exception &e) {
        std::cout << "Hanna error: " << e.what() << std::endl;
    }

    std::cout << "\n===== COPY TEST =====" << std::endl;

    try {
        Bureaucrat h("Ivy", 42);
        Bureaucrat copy(h);
        std::cout << "Original: " << h << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== ASSIGNMENT TEST =====" << std::endl;

    try {
        Bureaucrat i("Jack", 60);
        Bureaucrat j("Kate", 120);
        std::cout << "Before assignment:" << std::endl;
        std::cout << i << std::endl;
        std::cout << j << std::endl;

        j = i;

        std::cout << "After assignment:" << std::endl;
        std::cout << i << std::endl;
        std::cout << j << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== EDGE GRADES =====" << std::endl;

    try {
        Bureaucrat top("Top", 1);
        Bureaucrat bottom("Bottom", 150);
        std::cout << top << std::endl;
        std::cout << bottom << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
