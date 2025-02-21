#include	"../include/RobotomyRequestForm.hpp"

/*******************************************************/
/************** Constructors / Destructor **************/
/*******************************************************/

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default"){
	//std::cout << "Default Constructor RobotomyRequestForm called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){
	//std::cout << "Constructor with target called. target :" << this.getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45), _target(copy.getTarget())
{
	//std::cout << std::endl << "Constructor copy RobotomyRequestForm called" << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	//std::cout << std::endl << "Destructor RobotomyRequestForm called" << std::endl;
}

/*******************************************************/
/********************* Getters *************************/
/*******************************************************/

const std::string RobotomyRequestForm::getTarget() const{
	return (this->_target);
}
/*******************************************************/
/***************** member function *********************/
/*******************************************************/


#include <unistd.h>

static int half = 0;

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->_signed == false)
	{
		std::cout << this->getName() << " is not signed" << std::endl;
		return;
	}
	if (executor.getGrade() <= this->_gradeToExec)
	{
		std::cout << "robotization in progress " <<  std::flush;
		std::cout << "." << std::flush;
		sleep(1);
		std::cout << "." << std::flush;
		sleep(1);
		std::cout << "." << std::endl;
		sleep(1);
		std::cout << "VRRRRIIIIII" << std::endl;
		sleep(1);
		std::cout << "TAC-TAC-TAC-TAC" << std::endl;
		sleep(1);
		std::cout << "VRRRRIIIIII" << std::endl;
		sleep(1);
		if (half++ % 2 == 0)
			std::cout << this->getTarget() << " was robotomized" << std::endl;
		else
			std::cout << this->getTarget() << "'s romobization failed" << std::endl;
	}
	else
		throw RobotomyRequestForm::GradeTooLowException();
}

/*******************************************************/
/*************** Assignment operator *******************/
/*******************************************************/

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

/*******************************************************/
/*************** Operator overload << *****************/
/*******************************************************/

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& b)
{
	os << b.getName() << ", RobotomyRequestForm infos : " << b.getSigned() << ", " << b.getGradeToExec() << ", " << b.getSigned() << std::endl;
	return (os);
}
