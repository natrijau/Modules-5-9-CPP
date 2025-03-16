#include	"../include/ScalarConverter.hpp"

int     main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	if (!isprint(av[1][0]))
	{
		std::cerr << "Invalid input" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);		
	return (0);
}