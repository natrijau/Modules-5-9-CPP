#include	"../include/span.hpp"

Span::Span() : _size(0){};

Span::Span(unsigned int nb) : _size(nb){};

Span::Span(const Span &copy) : _N(copy._N), _size(copy._size){}

Span::~Span(){};

void Span::addNumber(unsigned int nbr)
{
	if (this->_N.size() < this->_size)
		this->_N.push_back(nbr);
	else
		throw	std::runtime_error("Tab full. Impossible to add number !");
}

void	Span::addRandomNumber()
{
	std::srand(std::time(0));
	for (size_t i = 0; i < this->_size; i++)
		this->_N.push_back(std::rand() % 555555555 + 1);
}

unsigned int Span::shortestSpan()
{
	if (this->_size < 2)
        throw std::runtime_error("Not enough elements");
	
	std::vector<unsigned int> tmp = this->_N;
	std::sort(tmp.begin(), tmp.end());
	unsigned int shortest = tmp[1] - tmp[0];
	
	for (size_t i = 1; i < this->_size; i++)
	{
		if (tmp[i] - tmp[i - 1] < shortest)
			shortest = tmp[i] - tmp[i - 1];
	}

	return (shortest);	
}

unsigned int Span::longestSpan()
{
	if (this->_size < 2)
		throw std::runtime_error("Not enough elements to find a span.");
	
	std::vector<unsigned int>::iterator minIt = std::min_element(this->_N.begin(), this->_N.end());
	std::vector<unsigned int>::iterator maxIt = std::max_element(this->_N.begin(), this->_N.end());
	return (*maxIt - *minIt);
}

void	Span::printN()
{
	for (size_t i = 0; i < this->_N.size(); i++)
		std::cout << i << " : " << this->_N[i] << std::endl;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
		this->_N = other._N;
	return (*this);
}