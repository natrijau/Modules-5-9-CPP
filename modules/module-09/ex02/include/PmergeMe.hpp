#ifndef	__PMERGEME_HPP__
#define	__PMERGEME_HPP__

#include	<iostream>
#include	<algorithm>
#include	<utility>
#include	<list>
#include	<vector>
#include	<ctime>

class PmergeMe
{
	private:
		//std::list<unsigned int> _numbersList;
		std::list<std::pair<int, int> > _numbersList;
		std::vector<unsigned int> _numbersVector;
		PmergeMe();
	public:
		PmergeMe(char **av);
		~PmergeMe();

		void 	addNumbersList(char **av);
		void 	addNumbersVector(char **av);
		void	sortList();
		void	sortVector();

		//unsigned int &operator[](unsigned int i);
};


#endif