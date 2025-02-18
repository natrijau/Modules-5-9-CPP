#include	"../include/Bureaucrat.hpp"

int     main(void)
{
	Bureaucrat* nathan;
	Bureaucrat* copyNathan;
	Form*		test;
	test = NULL;
	nathan = NULL;
	copyNathan = NULL;

	try
	{
		test = new Form("impot", 15, 1);
		Bureaucrat Yan("Yan", 150);
		Bureaucrat copyYan(Yan);
		//Yan.incrementGrade();
		//copyYan.decrementGrade();
		nathan = new Bureaucrat("Nathan", 150);
		//nathan->incrementGrade();
		nathan->signForm(*test);
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