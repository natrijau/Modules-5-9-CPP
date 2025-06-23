#ifndef	__PMERGEME_HPP__
#define	__PMERGEME_HPP__

#include	<iostream>
#include	<algorithm>
#include	<utility>
#include	<list>
#include	<vector>
#include	<ctime>
#include 	<iomanip>

class PmergeMe
{
	private:
		std::list<std::list<int> > _numbersList;
		std::vector<std::vector<int> > _numbersVector;
		PmergeMe();
	public:
		PmergeMe(char **av);
		~PmergeMe();

		void 	addNumbersList(char **av);
		void 	addNumbersVector(char **av);
		std::list<std::list<int> >	sortList(std::list<std::list<int> > &list);
		std::vector<std::vector<int> > sortVector(std::vector<std::vector<int> > &vec);
};


#endif