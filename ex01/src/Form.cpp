#include	"../include/Form.hpp"

/*******************************************************/
/************** Constructors / Destructor **************/
/*******************************************************/

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150){};

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << std::endl << "Constructor with params called" << std::endl;
	if (_gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150)
		throw GradeTooLowException();
	
	if (_gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToExec > 150)
		throw GradeTooLowException();	
}

Form::Form(const Form &copy)
: _name(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExec(copy.getGradeToExec())
{
	*this = copy;
	std::cout << std::endl << "Constructor default Form called" << std::endl;
}

Form::~Form() {
	std::cout << std::endl << "Destructor Form called" << std::endl;
}

/*******************************************************/
/********************* Getters *************************/
/*******************************************************/

const std::string	Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const{
	return (this->_signed);
}

int Form::getGradeToSign() const{
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const{
	return (this->_gradeToExec);
}

/*******************************************************/
/***************** member function *********************/
/*******************************************************/

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_signed = true;
	}
	else
		throw Form::GradeTooLowException();
}

/*******************************************************/
/*************** Assignment operator *******************/
/*******************************************************/

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

/*******************************************************/
/*************** Operator overload << *****************/
/*******************************************************/

std::ostream& operator<<(std::ostream& os, const Form& b)
{
	os << b.getName() << ", Form infos : " << b.getSigned() << ", " << b.getGradeToExec() << ", " << b.getSigned() << std::endl;
	return (os);
}
