#include	"../include/RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return (1);
	}
	try
	{
		RPN test(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

// a tester 
// ./RPN "8 9 + 1 7 - *"
/*
./RPN " 12 3 +"
./RPN "3 +"
./RPN "3 0 /"
*/