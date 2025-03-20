#ifndef	__SPAN_HPP__
#define	__SPAN_HPP__

#include	<stack>
#include	<list>
#include	<vector>
#include	<iostream>
#include 	<iterator>

template <typename T>
class MutantStack	: public std::stack<T>
{
	public:

	typedef typename	std::stack<T>::container_type::iterator iterator;

	typename	MutantStack<T>::iterator begin(){
		return (this->c.begin());
	}

	typename	MutantStack<T>::iterator end(){
		return (this->c.end());
	}
};

#endif