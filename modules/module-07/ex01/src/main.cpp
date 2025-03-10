#include	"../include/iter.hpp"

template <typename T>
void	printTab(T &elementArray)
{
	std::cout << elementArray << std::endl;
}

template <typename T>
void printTab2(T &elementArray)
{
	std::cout << "[" << elementArray[0] << ", " << elementArray[1] << "]" << std::endl;
}

template <typename T>
void swap(T &elementArray)
{
	int temp = elementArray[0];
	elementArray[0] = elementArray[1];
	elementArray[1] = temp;
}

int     main()
{
	int tab[] = {0, 1, 2, 3, 4, 5};
	iter(tab, 6, printTab<int>);

	int tab2[][2] = { {0, 1}, {0, 2}, {0, 3}, {0, 4} };
	iter(tab2, 4, printTab2<int[2]>);
	iter(tab2, 4, swap<int[2]>);
	iter(tab2, 4, printTab2<int[2]>);

	std::string tabString[] = { "Bonjour", "les", "amigos"};
	iter(tabString, 3, printTab<std::string>);

	std::string tabString2[][2] = {{"a", "b"}, {"c", "d"}, {"e", "f"}, {"g", "k"}};
	iter(tabString2, 4, printTab2<std::string[2]>);
	iter(tabString2, 4, swap<std::string[2]>);
	iter(tabString2, 4, printTab2<std::string[2]>);
	return (0);
}