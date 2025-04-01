#ifndef	__RPN_HPP__
#define	__RPN_HPP__

#include	<iostream>
#include	<stack>
#include	<algorithm>

class RPN
{
	private:
		std::stack<double> _stack;
		RPN();
	public:
		RPN(char *expr);
		~RPN();
};

#endif