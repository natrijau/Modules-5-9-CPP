#ifndef	ARRAY_HPP
#define	ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:

		T				*_array;
		unsigned int	_size;
	
	public:

		Array() : _array(NULL){};
		Array(unsigned int size) : _array(size) , _size(size){};
		Array(const Array &copy)	:	_array(copy._array), _size(copy._size) 
		{
			for (size_t i = 0; i < this->_size; i++)
				this->_array|[i] = copy._array[i];
		};
		~Array();

		const &operator=(const Array &other)
		{
			if (this != other)
			{
				this->_size = other._size;
				for (size_t i = 0; i < this->_size; i++)
					this->_array|[i] = copy._array[i];
			}
			return (this);
		};
};
//std::ostream &operator<<(std::ostream &os, const Array &b);

//template <typename T>
//T min(T a, T b) {
//	return (a < b) ? a : b;
//}

//template <typename T>
//T max(T a, T b) {
//	return (a > b) ? a : b;
//}

#endif