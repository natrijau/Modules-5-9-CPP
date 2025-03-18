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

		Array() : _array(), _size(0){}
		Array(unsigned int size) :	_size(size){
			this->_array = new T[size];
		}
		Array(const Array &copy)	:	_size(copy._size) 
		{
			this->_array = new T[copy._size];
			for (size_t i = 0; i < this->_size; i++){
				this->_array[i] = copy._array[i];
			}
		}
		~Array(){
			delete[] this->_array;
		}

		Array& operator=(const Array& other)
		{
			if (this != &other) {
				delete[] this->_array;
				this->_size = other._size;
				this->_array = new T[_size];
				for (size_t i = 0; i < _size; i++){
					this->_array[i] = other._array[i];
				}
			}
			return (*this);
		}

		class OutBounds : public	std::exception{
			public:
				virtual const	char* what() const throw(){
					return ("Index is out of bounds");
			}
		};
		
		T	&operator[](unsigned int	index){
			if (index >= this->_size)
				throw	Array::OutBounds();
			return (this->_array[index]);	
		}

		const T	&operator[](unsigned int	index) const{
			if (index >= this->_size)
				throw	Array::OutBounds();
			return (this->_array[index]);	
		}

		unsigned int size() const{
			return (this->_size);
		}
};
//std::ostream &operator<<(std::ostream &os, const Array &b);

#endif