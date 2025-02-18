#include	"../include/Bureaucrat.hpp"

void	copyForm(Form *toCopy)
{
	try
	{
		Form	copy(*toCopy);
		Bureaucrat bureaucrat("Boo", 150);
		delete(toCopy);
		bureaucrat.signForm(copy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	signForm(int gradeToSign, int gradeToExec)
{
	try
	{
		Form	test("Form", gradeToSign, gradeToExec);
		Bureaucrat	bureaucrat("Vegeta", 1);
		bureaucrat.signForm(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int     main(void)
{
	Bureaucrat* nathan;
	Form*		test;

	test = NULL;
	nathan = NULL;

	try
	{
		signForm(150, 150);
		signForm(1, 1);
		signForm(0, 0);
		signForm(151, 151);
		test = new Form("impot", 1, 1);
		copyForm(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	delete(nathan);

	return (0);
}