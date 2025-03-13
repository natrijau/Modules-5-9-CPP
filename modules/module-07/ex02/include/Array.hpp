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

		Array() : _array(NULL), _size(0){};
		Array(unsigned int size) :	_size(size){
			this._array = new T[this.size];
		};
		Array(const Array &copy)	:	_size(copy._size) 
		{
			this->_array = new T[this._size];
			for (unsigned int i = 0; i < this->_size; i++){
				this->_array|[i] = copy._array[i];
			}
		};
		~Array();

		Array& operator=(const Array& other)
		{
			if (this != &other) {
				delete[] this._array;
				this._size = other._size;
				this._array = new T[_size];
				for (unsigned int i = 0; i < _size; i++){
					this._array[i] = other._array[i];
				}
			}
			return (*this);
		}
		class OutBounds : public	std::exception{
			public:
				virtual const	char* what() const throw(){
					return ("Index is out of bounds");
			};
		};
		T	&operator[](int	index){
			if (index <= 0 || index > this->_size )
				throw	std::OutBounds();			
		};

		unsigned int size() const{
			return (this._size);
		}
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