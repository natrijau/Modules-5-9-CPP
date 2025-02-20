#include	"../include/AForm.hpp"

/*******************************************************/
/************** Constructors / Destructor **************/
/*******************************************************/

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150){
	//std::cout << "Default Constructor AForm called" << std::endl;
};

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	//std::cout << "Constructor with params called" << std::endl;
	std::cout << "AForm " << this->getName() << " :" << std::endl << "\t grade to sign -> " << _gradeToSign << std::endl << "\t grade to exec -> " << _gradeToExec << std::endl;
	
	if (_gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150)
		throw GradeTooLowException();
	
	if (_gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToExec > 150)
		throw GradeTooLowException();	
}

AForm::AForm(const AForm &copy)
: _name(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExec(copy.getGradeToExec())
{
	*this = copy;
	//std::cout << std::endl << "Constructor default AForm called" << std::endl;
}

AForm::~AForm() {
	//std::cout << std::endl << "Destructor AForm called" << std::endl;
}

/*******************************************************/
/********************* Getters *************************/
/*******************************************************/

const std::string	AForm::getName() const {
	return (this->_name);
}

bool AForm::getSigned() const{
	return (this->_signed);
}

int AForm::getGradeToSign() const{
	return (this->_gradeToSign);
}

int AForm::getGradeToExec() const{
	return (this->_gradeToExec);
}

/*******************************************************/
/***************** member function *********************/
/*******************************************************/

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		if (this->_signed == true)
		{
			std::cout << this->getName() << " AForm is already signed" << std::endl;
			return;
		}
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}

/*******************************************************/
/*************** Assignment operator *******************/
/*******************************************************/

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

/*******************************************************/
/*************** Operator overload << *****************/
/*******************************************************/

std::ostream& operator<<(std::ostream& os, const AForm& b)
{
	os << b.getName() << ", AForm infos : " << b.getSigned() << ", " << b.getGradeToExec() << ", " << b.getSigned() << std::endl;
	return (os);
}
