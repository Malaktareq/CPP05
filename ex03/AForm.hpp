#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
class Bureaucrat; 

class AForm
{
    private:
        std::string const _name;
        bool _isSigned;
        int const _signGrade;
        int const _executeGrade;
    public:
        AForm();
        AForm(std::string const name, int const signGrade, int const executeGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other) ;
        virtual ~AForm();
        void beSigned(Bureaucrat &bureaucrat);
        std::string const getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        virtual void execute(Bureaucrat const & executor) const = 0;
        class GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};
std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif