#include	"Intern.hpp"

/*******************************************************/
/************** Constructors / Destructor **************/
/*******************************************************/

Intern::Intern(){
	//std::cout << std::endl << "Constructor default Intern called" << std::endl;
}

Intern::Intern(const Intern &copy){
	*this = copy;
	//std::cout << std::endl << "Constructor copy called" << std::endl;
}

Intern::~Intern() {
	//std::cout << std::endl << "Destructor Bureaucrat called" << std::endl;
}

/*******************************************************/
/***************** Mumber function *********************/
/*******************************************************/

enum nameOfForms{
	ShrubberyCreationForm,
	RobotomyRequestForm,
	PresidentialPardonForm
};

AForm *Intern::makeForm(std::string nameForm, std::string target)
{
	enum nameOfForms myVar;
	for (size_t i = 0; i < 2; i++)
	{
	}
	
	switch (myVar) {
		case 1:
		 std::cout << "Low Level";
		  break;
		case 2:
		  std::cout << "Medium level";
		  break;
		case 3:
		  std::cout << "High level";
		  break;
	  }
	
}

/*******************************************************/
/*************** Assignment operator *******************/
/*******************************************************/

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		return (*this);
}

/*******************************************************/
/*************** Operator overload << *****************/
/*******************************************************/

std::ostream& operator<<(std::ostream& os, const Intern& b)
{
	os << b;
	return (os);
}
