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
	if (integer > 2147483647 || integer <= 0 || *endptr != '\0')
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
		char *endptr;
		this->_numbersList.push_back((int)std::strtoll(av[i], &endptr, 10));
	}
	std::cout << "Before:  ";
	for (std::list<unsigned int>::iterator it = this->_numbersList.begin(); it != this->_numbersList.end(); ++it){
        std::cout << *it << " ";
    }
	std::cout << std::endl;
}

void PmergeMe::addNumbersVector(char **av)
{
	for (size_t i = 1; av[i]; i++){
		char *endptr;
		this->_numbersVector.push_back((int)std::strtoll(av[i], &endptr, 10));
	}
	std::cout << "Before:  ";
	for (std::vector<unsigned int>::iterator it = this->_numbersVector.begin(); it != this->_numbersVector.end(); ++it){
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
	sortList();
	sortVector();
};

void PmergeMe::sortVector()
{
	std::vector<unsigned int> tmpMin;
	std::vector<unsigned int> tmpMax;

	std::vector<unsigned int>::iterator it = this->_numbersVector.begin();

	if (this->_numbersVector.size() % 2 == 1)
	{
		tmpMax.push_back(*it);
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
	std::cout << this->_numbersVector.size() << " : size" << std::endl;
	std::cout << "sortVector:  ";
	for (std::vector<unsigned int>::iterator it = this->_numbersVector.begin(); it != this->_numbersVector.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;	

	std::cout << "MinVector:  ";
	for (std::vector<unsigned int>::iterator it = tmpMin.begin(); it != tmpMin.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortList()
{
	std::cout << this->_numbersList.size() << " : size begin" << std::endl;
	std::list<unsigned int> tmpMin;
	std::list<unsigned int> tmpMax;

	std::list<unsigned int>::iterator it = this->_numbersList.begin();

	if (this->_numbersList.size() % 2 == 1)
	{
		tmpMin.push_back(*it);
		it = this->_numbersList.erase(it);
	}

	while (it != this->_numbersList.end())
	{
		unsigned int first = *it++;
		if (it == this->_numbersList.end())
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

	this->_numbersList = tmpMax;
	std::cout << this->_numbersList.size() << " : size" << std::endl;


	std::cout << "sortList:  ";
	for (std::list<unsigned int>::iterator it = this->_numbersList.begin(); it != this->_numbersList.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Minlist:  ";
	for (std::list<unsigned int>::iterator it = tmpMin.begin(); it != tmpMin.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	if (this->_numbersList.size() > 1)
		sortList();
	
	std::list<unsigned int> tmpIndex;
	size_t i = 0;
	while (i < this->_numbersList.size())
	{
		if (i % 2 == 0)
			tmpIndex.insert()
		/* code */
	}
			

	for (std::list<unsigned int>::iterator it = this->_numbersList.begin(); it != this->_numbersList.end(); ++it){
		std::cout << *it << " ";
	}	
}

PmergeMe::~PmergeMe(){};