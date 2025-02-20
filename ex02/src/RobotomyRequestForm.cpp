#include	"../include/PresidentialPardonForm.hpp"

/*******************************************************/
/************** Constructors / Destructor **************/
/*******************************************************/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 72, 45), _target("default"){
	//std::cout << "Default Constructor PresidentialPardonForm called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target){
	//std::cout << "Constructor with target called. target :" << this.getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardonForm", 25, 5), _target(copy.getTarget())
{
	//std::cout << std::endl << "Constructor copy PresidentialPardonForm called" << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	//std::cout << std::endl << "Destructor PresidentialPardonForm called" << std::endl;
}

/*******************************************************/
/********************* Getters *************************/
/*******************************************************/

const std::string PresidentialPardonForm::getTarget() const{
	return (this->_target);
}
/*******************************************************/
/***************** member function *********************/
/*******************************************************/

void PresidentialPardonForm::execute(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToExec)
	{
		if (this->_signed == false)
		{
			std::cout << this->getName() << " is not signed" << std::endl;
			return;
		}
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw PresidentialPardonForm::GradeTooLowException();
}

/*******************************************************/
/*************** Assignment operator *******************/
/*******************************************************/

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

/*******************************************************/
/*************** Operator overload << *****************/
/*******************************************************/

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b)
{
	os << b.getName() << ", PresidentialPardonForm infos : " << b.getSigned() << ", " << b.getGradeToExec() << ", " << b.getSigned() << std::endl;
	return (os);
}
