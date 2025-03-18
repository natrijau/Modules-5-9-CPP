#ifndef	__ITER_HPP__
#define	__ITER_HPP__

#include <iostream>

template <typename T>

void iter(T *array, size_t size, void function(T &))
{
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

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
	std::string temp = elementArray[0];
	elementArray[0] = elementArray[1];
	elementArray[1] = temp;
}
#endif