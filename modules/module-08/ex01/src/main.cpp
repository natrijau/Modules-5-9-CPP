#include	"../include/span.hpp"

int	main()
{
	//Span sp = Span(5);
	//sp.addNumber(6);
	//sp.addNumber(3);
	//sp.addNumber(17);
	//sp.addNumber(9);
	//sp.addNumber(11);

	//sp.printN();
	//std::cout << std::endl;
	//std::cout << sp.shortestSpan() << std::endl;
	//std::cout << sp.longestSpan() << std::endl;
	try
	{
		Span	sp = Span(5);
		std::vector<int> tmp ;
		tmp.push_back(5);
		tmp.push_back(3);
		tmp.push_back(1);
		tmp.push_back(6);
		int tmp[4] ={5, 4 , 3, 2};
		sp.addRandomNumber(tmp);
		sp.addNumber(2);
		sp.printN();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const  std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}