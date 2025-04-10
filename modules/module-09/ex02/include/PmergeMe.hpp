#ifndef	__PMERGEME_HPP__
#define	__PMERGEME_HPP__

#include	<iostream>
#include	<algorithm>
#include	<list>
#include	<vector>

class PmergeMe
{
	private:
		std::list<unsigned int> _numbersList;
		std::vector<unsigned int> _numbersVector;
		PmergeMe();
	public:
		PmergeMe(char **av);
		~PmergeMe();

		void 	addNumbersList(char **av);
		void 	addNumbersVector(char **av);
		void	sortList();
		void	sortVector();
};


#endif