#include	"../include/Bureaucrat.hpp"	

static	int i = 1;

void	copyForm(Form *toCopy)
{
	std::cout << std::endl << i << " test in copyForm()" << std::endl;
	i++;
	try
	{
		Form	copy(*toCopy);
		Bureaucrat bureaucrat("Boo", 150);
		delete(toCopy);
		bureaucrat.signForm(copy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	cantSign(int gradeToSign, int gradeToExec)
{
	std::cout << std::endl << i << " test in cantSign()" << std::endl;
	i++;
	try
	{
		Form	test("Form", gradeToSign, gradeToExec);
		Bureaucrat	bureaucrat("BUuuu", 150);
		bureaucrat.signForm(test);		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	signForm(int gradeToSign, int gradeToExec)
{
	std::cout << std::endl << i << " test in signForm()" << std::endl;
	i++;
	try
	{
		Form	test("Form", gradeToSign, gradeToExec);
		Bureaucrat	bureaucrat("Vegeta", 1);
		bureaucrat.signForm(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	alreadySigned(Form *toSign)
{
	std::cout << std::endl << i << " test in alreadySigned()" << std::endl;
	i++;
	try
	{
		Bureaucrat tmp("Temp", 1);
		tmp.signForm(*toSign);
		tmp.signForm(*toSign);
		delete(toSign);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int     main(void)
{
	try
	{
		Form*		test;
		test = NULL;
		signForm(150, 150);
		signForm(1, 1);
		signForm(0, 0);
		signForm(151, 151);
		cantSign(1, 1);
		test = new Form("impot", 150, 1);
		copyForm(test);
		test = new Form("impot", 1, 1);
		alreadySigned(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}