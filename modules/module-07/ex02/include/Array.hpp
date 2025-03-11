#ifndef	ARRAY_HPP
#define	ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:

		T				*_array;
		unsigned int	_size;
	
	public:

		Array() : _array(NULL) , _size(0){};

		Array(unsigned int n) : _size(n){
			this->_array = new T[n];
		};

		Array(const Array &copy) :	 _size(copy._size) 
		{
			this->_array = new T[copy._size];
			for (size_t i = 0; i < this->_size; i++)
			{
				this->_array[i] = copy._array[i];
			};
		};

		~Array(){
			if (this->_array.size() == 1)
				delete this->_array;
			else
				delete[] this->_array;		
		};

		class	OutBounds : public	std::exception{
			virtual const char* what() const throw()
			{
				return ("dasdsadas");
			};
		};

		Array &operator=(const Array &other)
		{
			delete[] this->_array;
			if (this != other)
			{
				this->_array = new T[other._size];
				this->_size = other._size;
				for (size_t i = 0; i < this->_size; i++)
				{
					this->_array[i] = other._array[i];
				}
			}
			return (*this);
		};

		const	T	&operator[](int idx) const{
			if(idx <= 0 || idx > this->_size){
				throw	OutBounds();
			}
    	    return (this->_array[idx]);
    	};

		unsigned int	size() const{
			return (this->_size);
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