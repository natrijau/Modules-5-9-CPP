#include	"../include/PmergeMe.hpp"

static bool strIntegerPositiv(char *str)
{
	if (!str || str[0] == '\0')
		return (false);

	for (size_t i = 0; str[i]; i++){
		if (!std::isdigit(str[i]))
			return (false);
	}

	char *endptr;
	long long integer = std::strtoll(str, &endptr, 10);
	if (integer > 2147483647 || integer < 0 || *endptr != '\0')
		return (false);
	return (true);
}

static bool allIntegerPositiv(char **av)
{
	for (size_t i = 1; av[i]; i++){
		if (!strIntegerPositiv(av[i]))
			return (false);
	}
	return (true);
}

void PmergeMe::addNumbersList(char **av)
{	
	for (size_t i = 1; av[i]; i++){
		if (av[i + 1]){
			this->_numbersList.push_back(std::make_pair((int)std::strtoll(av[i], NULL, 10), (int)std::strtoll(av[i + 1], NULL, 10)));
			i++;
		}
		else
			this->_numbersList.push_back(std::make_pair(-1, (int)std::strtoll(av[i], NULL, 10)));
	}
	std::cout << "Before:  ";
	for (std::list<std::pair<int, int> >::iterator it = this->_numbersList.begin() ; it != _numbersList.end() ; it++)
	{
		if (it->first < 0)
			std::cout << it->second;
		else		
			std::cout << it->first << " " << it->second << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::addNumbersVector(char **av)
{
	for (size_t i = 1; av[i]; i++){
		char *endptr;
		this->_numbersVector.push_back((int)std::strtoll(av[i], &endptr, 10));
	}
	int	i = 0;
	std::cout << "Before:  ";
	for (std::vector<unsigned int>::iterator it = this->_numbersVector.begin(); it != this->_numbersVector.end(); ++it , i++){
		if (i > 50)
		{
			std::cout << "[...]";
			break;
		}
        std::cout << *it << " ";
    }
	std::cout << std::endl;
}

PmergeMe::PmergeMe(char **av)
{
	if (!allIntegerPositiv(av))
		throw std::runtime_error("Error : one of the arguments is not a positive integer or exceeds the maximum integer !");
		//throw std::runtime_error("Error");
	addNumbersList(av);
	addNumbersVector(av);
	if (this->_numbersList.size() < 2)
		throw	std::runtime_error("Invalid number of integers to sort");

	std::clock_t startList = clock();
	sortList();
	clock_t endList = clock();

	clock_t start = clock();
	sortVector();
	clock_t end = clock();

	int	i = 0;
	std::cout << "After:  ";
	for (std::vector<unsigned int>::iterator it = this->_numbersVector.begin(); it != this->_numbersVector.end(); ++it, i++){
		if (i > 50)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _numbersList.size() << " elements with std::list : " << double(endList - startList) / CLOCKS_PER_SEC << " s" << std::endl;
	std::cout << "Time to process a range of " << _numbersVector.size() << " elements with std::vector : " << double(end - start) / CLOCKS_PER_SEC<< " s" << std::endl;
};

std::vector<unsigned int>	binaryInsertVector(std::vector<unsigned int> vector, unsigned int value)
{
	int	low = 0;
	int	high = vector.size() - 1;
	while (low <= high)
	{
		int	middle = (low + high) >> 1;
		if (vector[middle] < value)
			low = middle + 1;
		else
			high = middle - 1;
	}
	vector.insert(vector.begin() + low, value);
	return (vector);
}

std::vector<int> generateJacobsthal(int n)
{
	std::vector<int> seq;
	int a = 0;
	int	b = 1;
	while (b <= n)
	{
		if (seq.empty() || b != seq.back())
			seq.push_back(b);
		int c = b + 2 * a;  // J_n = J_{n-1} + 2 * J_{n-2}
		a = b;
		b = c;
	}
	return (seq);
}

void PmergeMe::sortVector()
{
	std::vector<unsigned int> tmpMin;
	std::vector<unsigned int> tmpMax;

	std::vector<unsigned int>::iterator it = this->_numbersVector.begin();

	if (this->_numbersVector.size() % 2 == 1)
	{
		tmpMin.push_back(*it);
		++it;
	}

	while (it != this->_numbersVector.end())
	{
		unsigned int first = *it++;
		if (it == this->_numbersVector.end())
		{
			tmpMax.push_back(first);
			break;
		}
		unsigned int second = *it++;

		if (first < second)
		{
			tmpMin.push_back(first);
			tmpMax.push_back(second);
		}
		else
		{
			tmpMin.push_back(second);
			tmpMax.push_back(first);
		}
	}
	this->_numbersVector = tmpMax;

	if (this->_numbersVector.size() - 1 > 1)
		sortVector();

	/*
	*/
	// Calcul de l'ordre d'insertion avec Jacobsthal
	int mList = tmpMin.size();
	std::vector<bool> insertedL(mList+1, false);
	std::vector<int> JL = generateJacobsthal(mList);
	std::vector<int> orderL;
	for (int i = (int)JL.size() - 1; i >= 1; --i) {
		int cur = JL[i];
		int prev = JL[i-1];
		for (int k = cur; k > prev; --k) {
			if (k <= mList && !insertedL[k]) {
				orderL.push_back(k);
				insertedL[k] = true;
			}
		}
	}
	for (int k = mList; k >= 1; --k) {
		if (!insertedL[k]) {
			orderL.push_back(k);
		}
	}
	
	/*

	*/

	for (std::vector<unsigned int>::iterator it = tmpMin.begin(); it != tmpMin.end(); ++it)
		this->_numbersVector = binaryInsertVector(this->_numbersVector, *it);
}

std::list<unsigned int>	binaryInsert(std::list<unsigned int> list, unsigned int value)
{
	int	low = 0;
	int	high = list.size() - 1;
	std::list<unsigned int>::iterator it = list.begin();
	while (low <= high)
	{
		it = list.begin();
		int	middle = (low + high) >> 1;
		for (int i = 0; i < middle; ++i)
			++it;
		if (*it < value)
			low = middle + 1;
		else
			high = middle - 1;
	}
	it = list.begin();
	for (int i = 0; i < low; i++, it++);
	list.insert(it, value);
	return (list);
}

void PmergeMe::sortList()
{
	std::list<std::pair<int, int> >::iterator it = this->_numbersList.begin();
	for (; it != _numbersList.end() ; it++)
	{
		std::cout << " " << it->first << " " << it->second << std::endl;
		/* code */
	}
	
	std::list<unsigned int> tmpMin;
	std::list<unsigned int> tmpMax;

	//std::list<unsigned int>::iterator it = this->_numbersList.begin();

	//if (this->_numbersList.size() % 2 == 1)
	//{
	//	tmpMin.push_back(*it);
	//	it = this->_numbersList.erase(it);
	//}

	//while (it != this->_numbersList.end())
	//{
	//	unsigned int first = *it++;
	//	if (it == this->_numbersList.end())
	//	{
	//		tmpMax.push_back(first);
	//		break;
	//	}
	//	unsigned int second = *it++;

	//	if (first < second)
	//	{
	//		tmpMin.push_back(first);
	//		tmpMax.push_back(second);
	//	}
	//	else
	//	{
	//		tmpMin.push_back(second);
	//		tmpMax.push_back(first);
	//	}
	//}
	//this->_numbersList = tmpMax;
	//if (this->_numbersList.size() - 1 > 1)
	//	sortList();

	//for (std::list<unsigned int>::iterator it = tmpMin.begin(); it != tmpMin.end(); ++it)
	//	this->_numbersList = binaryInsert(this->_numbersList, *it);
}

PmergeMe::~PmergeMe(){};