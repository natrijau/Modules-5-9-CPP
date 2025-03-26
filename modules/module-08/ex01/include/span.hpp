#ifndef	__SPAN_HPP__
#define	__SPAN_HPP__

#include	<iostream>
#include	<vector>
#include 	<algorithm>
#include	<ctime>
#include 	<unistd.h>
#include 	<fstream>

class Span
{
	private:
		std::vector<int> _N;
		unsigned int	_size;
	public:
		Span();
		Span(const Span& copy);
		Span(unsigned int i);
		~Span();

		void			addNumber(int nbr);
		void			addRandomNumber(int *tab);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			printN();

		Span	&operator=(const Span& other);
};

#endif