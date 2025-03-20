#include	"../include/span.hpp"

void	spanDefault()
{
	try
	{
		std::cout << "Default constructor call" << std::endl;
		Span span;
		std::cout << "shortestSpan called withat elements" << std::endl;
		span.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	randNbr()
{
	try
	{
		std::cout << "randNbr" << std::endl;
		Span	sp = Span(10);
		sp.addRandomNumber();
		std::cout << "PRINT NEW TAB :" << std::endl;
		sp.printNbr();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	shortAndLong()
{
	try
	{
		std::cout << "shortAndLong()" << std::endl;
		Span	sp = Span(10);
		sp.addRandomNumber();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main()
{
	try
	{
		spanDefault();
		std::cout << std::endl;
		randNbr();
		std::cout << std::endl;
		shortAndLong();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}