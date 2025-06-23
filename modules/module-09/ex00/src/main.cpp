#include	"../include/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac == 1)
			std::cerr << "Error: could not open file." << std::endl;
		else
			std::cerr << "Invalid number of arguments." << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}