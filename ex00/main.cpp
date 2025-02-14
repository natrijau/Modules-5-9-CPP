#include	"Bureaucrat.hpp"

int     main()
{
    Bureaucrat bureaucrat1("yan", 150);

    try
    {
        bureaucrat1.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}