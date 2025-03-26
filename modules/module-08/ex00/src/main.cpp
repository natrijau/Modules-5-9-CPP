#include	"../include/easyfind.hpp"

void	haveNotInteger()
{
	try
	{
		std::vector<int> v(4, 100);
		std::vector<int>::iterator it = easyfind(v, 42);
		(void)it;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	haveInteger()
{
	try
	{
		std::vector<int> v(4, 100);
		v.push_back(42);
		std::vector<int>::iterator it = easyfind(v, 42);
		std::cout << "Nb found in vector v : " << *it << std::endl;
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
		haveInteger();
		std::cout << std::endl;
		haveNotInteger();
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}