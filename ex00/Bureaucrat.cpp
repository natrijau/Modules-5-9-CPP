#include	"Bureaucrat.hpp"

/*******************************************************/
/**********************Constructors*********************/
/*******************************************************/


//Constructor default
Bureaucrat::Bureaucrat()
: _name("default"), _range(NULL) {}

//Constructor Copy
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
: _name(copy._name), _range(copy._range)
{}

//Constructor with params
Bureaucrat::Bureaucrat(std::string name, int range)
: _name(name), _range(range)
{
	if (range < 1)
		GradeTooHighException();
	else if (range > 150)
		GradeTooLowException();
	this->_range = range;	
}

//Destructor 
Bureaucrat::~Bureaucrat() {}

/*******************************************************/
/**********************Gets*****************************/
/*******************************************************/

std::string	Bureaucrat::getName() const;


// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	//! _name const
	if (this != &other)
		this->_range = other._range;
	return (*this);
}
