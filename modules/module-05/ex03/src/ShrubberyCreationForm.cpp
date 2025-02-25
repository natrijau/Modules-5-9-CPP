#include	"../include/ShrubberyCreationForm.hpp"

/*******************************************************/
/************** Constructors / Destructor **************/
/*******************************************************/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default"){
	//std::cout << "Default Constructor ShrubberyCreationForm called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){
	//std::cout << "Constructor with target called. target :" << this.getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137), _target(copy.getTarget())
{
	//std::cout << std::endl << "Constructor copy ShrubberyCreationForm called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	//std::cout << std::endl << "Destructor ShrubberyCreationForm called" << std::endl;
}

/*******************************************************/
/********************* Getters *************************/
/*******************************************************/

const std::string ShrubberyCreationForm::getTarget() const{
	return (this->_target);
}
/*******************************************************/
/***************** member function *********************/
/*******************************************************/

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->_signed == false)
	{
		std::cout << this->getName() << " is not signed" << std::endl;
		return;
	}
	if (executor.getGrade() <= this->_gradeToExec)
	{
		std::ofstream file((this->getTarget() + "_shrubbery.txt").c_str());
		if (!file)
			std::cerr << "Error creating file!" << std::endl;
		file	<< "       *       " << std::endl
				<< "      ***             *       " << std::endl
				<< "     *****           ***      " << std::endl
				<< "    *******         *****     " << std::endl
				<< "   *********       *******    " << std::endl
				<< "  ***********        |||      " << std::endl
				<< " ************* " << std::endl
				<< "      |||      " << std::endl
				<< "      |||      *" << std::endl
				<< "              ***      " << std::endl
				<< "             *****     " << std::endl
				<< "              |||      " << std::endl;
		file.close();
		std::cout << "Shrubbery created at " << this->getTarget() + "_shrubbery" << std::endl;
	}
	else
		throw ShrubberyCreationForm::GradeTooLowException();
}

/*******************************************************/
/*************** Assignment operator *******************/
/*******************************************************/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

/*******************************************************/
/*************** Operator overload << *****************/
/*******************************************************/

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& b)
{
	os << b.getName() << ", ShrubberyCreationForm infos : " << b.getSigned() << ", " << b.getGradeToExec() << ", " << b.getSigned() << std::endl;
	return (os);
}
