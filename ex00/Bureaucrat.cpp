#include	"Bureaucrat.hpp"

/*******************************************************/
/**********************Constructors*********************/
/*******************************************************/


//Constructor default
Bureaucrat::Bureaucrat()
: _name("default"), _range(1) {}

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

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}


int	Bureaucrat::getGrade() const
{
	return (this->_range);
}

// /*******************************************************/
// /******************GradeException***********************/
// /*******************************************************/

// void	Bureaucrat::GradeTooHighException()
// {
// 	std::cout << "Range to hight. Maximum grade its 1" << std::endl;
// }

// void	Bureaucrat::GradeTooLowException()
// {
// 	std::cout << "Range to low. Minimum grade its 150" << std::endl;
// }


/*******************************************************/
/**************Decrement and Increment******************/
/*******************************************************/

void	Bureaucrat::decrementGrade()
{
	this->_range++;
}

void	Bureaucrat::incrementGrade()
{
	this->_range--;
}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	//! _name const
	if (this != &other)
		this->_range = other._range;
	return (*this);
}
