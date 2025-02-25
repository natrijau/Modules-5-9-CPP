#include	"../include/Bureaucrat.hpp"

/*******************************************************/
/********************* Exceptions **********************/
/*******************************************************/

class	Bureaucrat::GradeTooLowException : public	std::exception
{
	private:
		std::string _message;
	public:
		GradeTooLowException(std::string name) : _message(name + " : Rating too low. Minimum rating is 150"){};
		virtual ~GradeTooLowException() throw(){};
		virtual const	char* what() const throw()
		{
			return (_message.c_str());
    	};
};

class	Bureaucrat::GradeTooHighException : public	std::exception
{
	private:
		std::string _message;	
	public:
		GradeTooHighException(std::string name) : _message(name + " : Rating too high. Maximum rating is 1"){};
		virtual ~GradeTooHighException() throw(){};
		virtual const	char* what() const throw()
		{
			return (_message.c_str());
    	};
};

/*******************************************************/
/************** Constructors / Destructor **************/
/*******************************************************/

Bureaucrat::Bureaucrat() : _name("default"), _range(1) {
	//std::cout << std::endl << "Constructor default Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _range(copy.getGrade()) {
	//std::cout << std::endl << "Constructor copy called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int range) : _name(name)
{
	//std::cout << std::endl << "Constructor with params called" << std::endl;
	std::cout << RED << "Bureaucrat named " << this->getName() << " :" << std::endl << "\t grade -> " << range << RESET << std::endl;
	if (range < 1)
		throw GradeTooHighException(this->getName());
	else if (range > 150)
		throw GradeTooLowException(this->getName());
	else
		this->_range = range;	
}

Bureaucrat::~Bureaucrat() {
	//std::cout << std::endl << "Destructor Bureaucrat called" << std::endl;
}

/*******************************************************/
/********************* Getters *************************/
/*******************************************************/

std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int	Bureaucrat::getGrade() const {
	return (this->_range);
}

/*******************************************************/
/************* Decrement and Increment *****************/
/*******************************************************/

void	Bureaucrat::decrementGrade() {
	if (_range < 150)
	{
		this->_range++;
		std::cout << RED << this->getName() << " : New grade of " << this->getName() << "its " << this->getGrade() << RESET << std::endl;
	}
	else
		throw GradeTooLowException(this->getName());
}

void	Bureaucrat::incrementGrade() {
	if (_range > 1) {
		this->_range--;
		std::cout << RED << this->getName() << " : New grade of " << this->getName() << " its " << this->getGrade() << RESET << std::endl;
	}
	else
		throw GradeTooHighException(this->getName());
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		std::cout << RED << this->getName() << " try to sign the form named " << form.getName() << RESET << std::endl; 
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

/*******************************************************/
/*************** Assignment operator *******************/
/*******************************************************/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_range = other._range;
	return (*this);
}

/*******************************************************/
/*************** Operator overload << *****************/
/*******************************************************/

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade : " << b.getGrade();
	return (os);
}
