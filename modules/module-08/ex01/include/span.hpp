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
		Span(unsigned int i);
		Span(const Span& copy);
		~Span();

		void			addNumber(int nbr);
		void			addRandomNumber(std::vector<int> tmp);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			printN();

		Span	&operator=(const Span& other);
};

#endif