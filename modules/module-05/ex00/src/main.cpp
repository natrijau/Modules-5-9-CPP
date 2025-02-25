#include	"../include/Bureaucrat.hpp"

int     main(void)
{
	Bureaucrat* nathan;
	Bureaucrat* copyNathan;

	nathan = NULL;
	copyNathan = NULL;

	try
	{
		Bureaucrat Yan("Yan", 150);
		Bureaucrat copyYan(Yan);
		Yan.incrementGrade();
		//copyYan.decrementGrade();
		nathan = new Bureaucrat("Nathan", 1);
		nathan->incrementGrade();
		//copyNathan = new Bureaucrat(*nathan);
		//copyNathan->decrementGrade();
		//nathan->incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	delete(nathan);
	delete(copyNathan);

	return (0);
}