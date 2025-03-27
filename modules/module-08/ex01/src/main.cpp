#include	"../include/span.hpp"

void	noSize()
{
	try
	{
		Span	span;
		span.addNumber(1);
		std::cout << "OK " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " <<  e.what() << '\n';
	}
}

void withSize()
{
	try
	{
		Span	sp(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(1);
		sp.addNumber(6);
		sp.addNumber(2);
		//sp.printN();
		std::cout << "OK " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}
}

void shortSpan()
{
	try
	{
		Span	sp(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(1);
		sp.addNumber(6);
		sp.addNumber(2);
		//sp.printN();
		std::cout << "The shortest span is : " << sp.shortestSpan() << std::endl;
		std::cout << "OK " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}
}

void longSpan()
{
	try
	{
		Span	sp(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(1);
		sp.addNumber(6);
		sp.addNumber(2);
		//sp.printN();
		std::cout << "The longest span is : " << sp.longestSpan() << std::endl;
		std::cout << "OK " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}
}

void randNb()
{
	try
	{
		Span	sp(100);
		std::vector<int> tmp ;
		std::srand(std::time(0));
		std::cout << "Add 100000 integer " << std::endl;
		for (size_t i = 0; i < 100; i++)
		{
			sleep(0.1);
			tmp.push_back(std::rand() % -500000  -25252);
		}
		sp.addRandomNumber(tmp);
		sp.printN();
		std::cout << "The longest span is : " << sp.longestSpan() << std::endl;
		std::cout << "The shortest span is : " << sp.shortestSpan() << std::endl;
		std::cout << "OK " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}
}

int	main()
{
	try
	{
		std::cout << "Test noSize()" << std::endl;
		noSize();
		std::cout << std::endl << "Test withSize()" << std::endl;
		withSize();
		std::cout << std::endl << "Test shortSpan()" << std::endl;
		shortSpan();
		std::cout << std::endl << "Test longSpan()" << std::endl;
		longSpan();
		std::cout << std::endl << "Test randomNbr()" << std::endl;
		randNb();		
	}
	catch(const  std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}