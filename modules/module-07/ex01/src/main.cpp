#include	"../include/iter.hpp"



int     main()
{
	int tab[] = {0, 1, 2, 3, 4, 5};
	iter(tab, 6, printTab<int>);
	std::cout << std::endl;

	std::string tabString2[][2] = {{"a", "b"}, {"c", "d"}, {"e", "f"}, {"g", "k"}};
	iter(tabString2, 4, printTab2<std::string[2]>);
	iter(tabString2, 4, swap<std::string[2]>);
	std::cout << std::endl;
	iter(tabString2, 4, printTab2<std::string[2]>);
	return (0);
}