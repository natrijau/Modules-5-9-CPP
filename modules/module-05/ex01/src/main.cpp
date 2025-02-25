#include	"../include/Bureaucrat.hpp"	

static	int i = 1;

void	copyForm()
{
	Form*		toCopy;
	toCopy = NULL;

	std::cout << "/*******************************************************/" << std::endl;			
	std::cout << "\t\t"<< i << " test in copyForm()" << std::endl;
	std::cout << "/*******************************************************/" << std::endl;			
	i++;
	
	try
	{
		toCopy = new Form("impot", 150, 1);
		Form	copy(*toCopy);
		delete(toCopy);
		Bureaucrat bureaucrat("Boo", 150);
		bureaucrat.signForm(copy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	cantSign(int gradeToSign, int gradeToExec)
{
	std::cout << "/*******************************************************/" << std::endl;			
	std::cout << "\t\t"<< i << " test in cantSign()" << std::endl;
	std::cout << "/*******************************************************/" << std::endl;			
	i++;
	try
	{
		Form	form("Form", gradeToSign, gradeToExec);
		Bureaucrat	bureaucrat("BUuuu", 150);
		bureaucrat.signForm(form);		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	signForm(int gradeToSign, int gradeToExec)
{
	std::cout << "/*******************************************************/" << std::endl;			
	std::cout << "\t\t"<< i << " test in signForm()" << std::endl;
	std::cout << "/*******************************************************/" << std::endl;			
	i++;
	try
	{
		Form	form("Form", gradeToSign, gradeToExec);
		Bureaucrat	bureaucrat("Vegeta", 1);
		bureaucrat.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	alreadySigned()
{
	std::cout << "/*******************************************************/" << std::endl;			
	std::cout << "\t\t"<< i << " test in alreadySigned() " << std::endl;
	std::cout << "/*******************************************************/" << std::endl;			
	i++;

	try
	{
		Form		form("Form", 1, 1);
		Bureaucrat	bureaucrat("Vegeta", 1);
		bureaucrat.signForm(form);
		bureaucrat.signForm(form);
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
		signForm(150, 150);
		std::cout << std::endl;
		signForm(1, 1);
		std::cout << std::endl;
		signForm(0, 0);
		std::cout << std::endl;
		signForm(151, 151);
		std::cout << std::endl;
		cantSign(1, 1);
		std::cout << std::endl;
		copyForm();
		std::cout << std::endl;
		alreadySigned();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}