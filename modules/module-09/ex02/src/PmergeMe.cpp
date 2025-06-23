#include "../include/PmergeMe.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <ctime>
#include <cmath>

static	int	DEBUG_MODE = 0;


// Pour les couleurs
const char* RESET = "\033[0m";
const char* RED = "\033[31m";
const char* GREEN = "\033[32m";
const char* YELLOW = "\033[33m";
const char* BLUE = "\033[34m";
const char* MAGENTA = "\033[35m";
const char* CYAN = "\033[36m";

static void printList(const std::list<std::list<int> > &list) {
	int i = 0;
	for (std::list<std::list<int> >::const_iterator it = list.begin(); it != list.end(); ++it , i++) {
		std::cout << CYAN << "( ";
		for (std::list<int>::const_iterator itList = it->begin(); itList != it->end(); ++itList) {
			std::cout << *itList << " ";
		}
		if (i == 50){
			std::cout << "[...]";
			break;
		}

		std::cout << ")" << RESET;
	}
	std::cout << std::endl;
}

static void printVector(const std::vector<std::vector<int> > &vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << CYAN << "( ";
        for (size_t j = 0; j < vec[i].size(); ++j) {
            std::cout << vec[i][j] << " ";
        }
		if (i == 50){
			std::cout << "[...]";
			break;
		}
		std::cout << ")" << RESET;
    }
    std::cout << std::endl;
}

static bool strIntegerPositiv(char *str) {
	if (!str || str[0] == '\0')
		return false;
	for (size_t i = 0; str[i]; i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	char *endptr;
	long long integer = std::strtoll(str, &endptr, 10);
	if (integer > 2147483647 || integer < 0 || *endptr != '\0')
		return false;
	return true;
}

static bool allIntegerPositiv(char **av) {
	for (size_t i = 1; av[i]; i++) {
		if (!strIntegerPositiv(av[i]))
			return false;
	}
	return true;
}

void PmergeMe::addNumbersList(char **av) {
	for (size_t i = 1; av[i]; i++) {
		std::list<int> tmp;
		char *endptr;
		tmp.push_back((int)std::strtoll(av[i], &endptr, 10));
		if (i < 50)
			std::cout << av[i] << " ";
		if (i == 50)
			std::cout << "[...]";
		this->_numbersList.push_back(tmp);
	}
	std::cout << std::endl;
}

void PmergeMe::addNumbersVector(char **av) {
	std::cout << "Before :   ";
	for (size_t i = 1; av[i]; i++) {
		std::vector<int> tmp;
		char *endptr;
		tmp.push_back((int)std::strtoll(av[i], &endptr, 10));
		if (i < 50)
			std::cout << RED <<  av[i] << " ";
		if (i == 50)
			std::cout << "[...]";
		this->_numbersVector.push_back(tmp);
	}
	std::cout << std::endl << RESET;
}

double getTimeMicroseconds() {
	return static_cast<double>(std::clock()) * 1e6 / CLOCKS_PER_SEC;
}

PmergeMe::PmergeMe(char **av) {
	if (!allIntegerPositiv(av))
		throw std::runtime_error("Error: one of the arguments is not a positive integer or exceeds the maximum integer!");

	double startList = getTimeMicroseconds();
	addNumbersList(av);
	if (this->_numbersList.size() < 2)
		throw std::runtime_error("Invalid number of integers to sort");	
	_numbersList = sortList(_numbersList);
	double endList = getTimeMicroseconds();

	double start = getTimeMicroseconds();
	addNumbersVector(av);
	_numbersVector = sortVector(_numbersVector);
	double end = getTimeMicroseconds();
	
	std::cout << GREEN << std::endl << "After :   ";
	int i = 0;
	for (std::list<std::list<int> >::const_iterator it = _numbersList.begin(); it != _numbersList.end(); ++it , i++) {
		for (std::list<int>::const_iterator itList = it->begin(); itList != it->end(); ++itList) {
			std::cout << *itList << " ";
		}
		if (i == 50){
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;

	std::cout << RESET << std::fixed << std::setprecision(5) <<  "Time to process a range of " << _numbersList.size() << " elements with std::list: " << (endList - startList) << " us" << std::endl;
	std::cout << std::fixed << std::setprecision(5) <<  "Time to process a range of " << _numbersVector.size() << " elements with std::vector: " << (end - start) << " us" << std::endl;
}

static void insertElementsList(std::list<std::list<int> > &pend, std::list<std::list<int> > &main) {
	static const size_t jacobsthal[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531};
	for (size_t i = 1; jacobsthal[i] < pend.size() && jacobsthal[i] != 0; ++i) {
		size_t index = jacobsthal[i];
		if (index >= pend.size()) {
			index = pend.size() - 1;
		}

		std::list<std::list<int> >::iterator it = pend.begin();
		std::advance(it, index);
		std::list<int> element = *it;
		pend.erase(it);

		std::list<std::list<int> >::iterator pos = main.begin();
		while (pos != main.end() && *(--(pos->end())) < *(--(element.end()))) {
			++pos;
		}
		main.insert(pos, element);
	}

	while (!pend.empty()) {
		std::list<int> element = pend.front();
		pend.pop_front();
		std::list<std::list<int> >::iterator pos = main.begin();
		while (pos != main.end() && *(--(pos->end())) < *(--(element.end()))) {
			++pos;
		}
		main.insert(pos, element);
	}
}

static void insertElementsVector(std::vector<std::vector<int> > &pend, std::vector<std::vector<int> > &main) {
	static const size_t jacobsthal[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531};

    std::vector<bool> used(pend.size(), false);

    for (size_t i = 1; jacobsthal[i] < pend.size(); ++i) {
        size_t index = jacobsthal[i];
        if (index >= pend.size())
            break;
        if (used[index])
            continue;
        used[index] = true;

        std::vector<int> element = pend[index];
        std::vector<std::vector<int> >::iterator pos = main.begin();
        while (pos != main.end() && pos->back() < element.back())
            ++pos;
        main.insert(pos, element);
    }

    for (size_t i = 0; i < pend.size(); ++i) {
        if (used[i])
            continue;
        std::vector<int> element = pend[i];
        std::vector<std::vector<int> >::iterator pos = main.begin();
        while (pos != main.end() && pos->back() < element.back())
            ++pos;
        main.insert(pos, element);
    }
}

static std::list<std::list<int> > unpairList(std::list<std::list<int> > &original) {
	std::list<std::list<int> > result;
	for (std::list<std::list<int> >::iterator it = original.begin(); it != original.end(); ++it) {
		std::list<int> firstHalf, secondHalf;
		size_t mid = it->size() / 2;
		size_t i = 0;
		for (std::list<int>::iterator jt = it->begin(); jt != it->end(); ++jt, ++i) {
			if (i < mid)
				firstHalf.push_back(*jt);
			else
				secondHalf.push_back(*jt);
		}
		if (!firstHalf.empty())
			result.push_back(firstHalf);
		if (!secondHalf.empty())
			result.push_back(secondHalf);
	}
	return result;
}

static std::vector<std::vector<int> > unpairVector(std::vector<std::vector<int> > &original) {
    std::vector<std::vector<int> > result;

    for (std::vector<std::vector<int> >::iterator it = original.begin(); it != original.end(); ++it) {
        std::vector<int> firstHalf, secondHalf;
        size_t mid = it->size() / 2;

        for (size_t i = 0; i < it->size(); ++i) {
            if (i < mid)
                firstHalf.push_back((*it)[i]);
            else
                secondHalf.push_back((*it)[i]);
        }
        if (!firstHalf.empty())
            result.push_back(firstHalf);
        if (!secondHalf.empty())
            result.push_back(secondHalf);
    }

    return result;
}

std::vector<std::vector<int> > PmergeMe::sortVector(std::vector<std::vector<int> > &vec) {
	if (vec.size() <= 1)
		return vec;

	std::vector<std::vector<int> > main;
	std::vector<std::vector<int> > pend;
	std::vector<std::vector<int> > last;

	size_t i = 0;
	while (i < vec.size()) {
		std::vector<int> first = vec[i++];
		if (i < vec.size()) {
			std::vector<int> second = vec[i++];
			int nb1 = first.back();
			int nb2 = second.back();
			if (nb2 < nb1)
				std::swap(first, second);
			first.insert(first.end(), second.begin(), second.end());
			main.push_back(first);
		} else {
			last.push_back(first);
		}
	}

	if (DEBUG_MODE == 1) {
		std::cout << MAGENTA << "(Post recursiv) Main after pairing: " << RESET;
		printVector(main);
		std::cout << MAGENTA << "(Post recursiv) Last after pairing: " << RESET;
		printVector(last);
		std::cout << "\n";
	}

	if (main.size() > 1)
		main = sortVector(main);
	main = unpairVector(main);

	std::vector<std::vector<int> > filteredMain;
	for (size_t j = 0; j < main.size(); ++j) {
		if (j % 2 == 0 && j >= 2)
			pend.push_back(main[j]);
		else
			filteredMain.push_back(main[j]);
	}
	main = filteredMain;

	if (DEBUG_MODE == 1) {
		std::cout << std::endl;
		std::cout << YELLOW << "(after recursiv) Main before insert: " << RESET;
		printVector(main);
		std::cout << YELLOW << "(after recursiv) Pend before insert: " << RESET;
		printVector(pend);
		std::cout << YELLOW << "(after recursiv) last before insert: " << RESET;
		printVector(last);
	}
	
	insertElementsVector(pend, main);
	insertElementsVector(last, main);

	if (DEBUG_MODE == 1) {
		std::cout << std::endl;
		std::cout << BLUE << "(after depaired) Main: " << RESET;
		printVector(main);
		std::cout << BLUE << "(after depaired) Pend: " << RESET;
		printVector(pend);
		std::cout << BLUE << "(after depaired) Last: " << RESET;
		printVector(last);
	}

	return main;
}

std::list<std::list<int> > PmergeMe::sortList(std::list<std::list<int> > &list) {
	if (list.size() <= 1)
		return list;
	std::list<std::list<int> > main;
	std::list<std::list<int> > pend;
	std::list<std::list<int> > last;
	std::list<std::list<int> >::iterator it = list.begin();
	while (it != list.end() && list.size() > 1) {
		std::list<std::list<int> >::iterator first = it++;
		if (it != list.end()) {
			std::list<std::list<int> >::iterator second = it++;
			int nb1 = *(--(first->end()));
			int nb2 = *(--(second->end()));
			if (nb2 < nb1) {
				std::iter_swap(first, second);
			}
			first->splice(first->end(), *second);
			main.push_back(*first);
		} else {
			last.push_back(*first);
		}
	}

	if (DEBUG_MODE == 1) {
		std::cout << MAGENTA << "(Post recursiv) Main after pairing: " << RESET;
		printList(main);
		std::cout << MAGENTA << "(Post recursiv) Last after pairing: " << RESET;
		printList(last);
		std::cout << "\n";
	}

	if (main.size() > 1)
		main = sortList(main);
	
	//	desappairer main
	main = unpairList(main);

	std::list<std::list<int> >::iterator test = main.begin();
	std::list<std::list<std::list<int> >::iterator> toErase;

	// constitution du pend a partir du main
	for (size_t i = 0; i < main.size(); i++, test++) {
		if (i % 2 == 0 && i >= 2) {
			pend.push_back(*test);
			toErase.push_back(test);
		}
	}

	// Filtrer les éléments de main pour ne garder que ceux à insérer
	for (std::list<std::list<std::list<int> >::iterator>::iterator it = toErase.begin(); it != toErase.end(); ++it) {
		main.erase(*it);
	}

	if (DEBUG_MODE == 1) {
		std::cout << std::endl;
		std::cout << YELLOW << "(after recursiv) Main before insert: " << RESET;
		printList(main);
		std::cout << YELLOW << "(after recursiv) Pend before insert: " << RESET;
		printList(pend);
		std::cout << YELLOW << "(after recursiv) last before insert: " << RESET;
		printList(last);
	}

	if (pend.size() == 0 && last.size() == 0)
		return main;

	insertElementsList(pend, main);
	insertElementsList(last, main);

	if (DEBUG_MODE == 1	)
	{
		std::cout << std::endl;
		std::cout << BLUE << "(after depaired) Main: " << RESET;
		printList(main);
		std::cout << BLUE << "(after depaired) Pend: " << RESET;
		printList(pend);
		std::cout << BLUE << "(after depaired) Last: " << RESET;
		printList(last);
	}
	
	return main;
}

PmergeMe::~PmergeMe() {}
