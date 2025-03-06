#ifndef	__ITER_HPP__
#define	__ITER_HPP__

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t size, F function) {
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

#endif