#include	"../include/Intern.hpp"

class	Intern::InternException : public	std::exception
{
	private:
		std::string _message;
	public:
		virtual ~InternException() throw(){};
		virtual const	char* what() const throw()
		{
			return ("Error: Unknown form type");
    	};
};

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
	ShrubberyCreation,
	RobotomyRequest,
	PresidentialPardon
};

AForm *Intern::makeForm(std::string nameForm, std::string target)
{
	std::string	formName[3] = { "shrub creation", "robotomy request", "presidential pardon"};
	int	i = 0;
	for (; i < 3; i++)
	{
		if (formName[i] == nameForm)
			break;
	}
	switch (i)
	{
        case ShrubberyCreation:
            std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return new ShrubberyCreationForm(target);
        case RobotomyRequest:
            std::cout << "Intern creates RobotomyRequestForm" << std::endl;
            return new RobotomyRequestForm(target);
        case PresidentialPardon:
            std::cout << "Intern creates PresidentialPardonForm" << std::endl;
            return new PresidentialPardonForm(target);
		default:
			throw	InternException();
			break;
	}
}

/*******************************************************/
/*************** Assignment operator *******************/
/*******************************************************/

Intern &Intern::operator=(const Intern &)
{
	return (*this);
}

/*******************************************************/
/*************** Operator overload << *****************/
/*******************************************************/

std::ostream& operator<<(std::ostream& os, const Intern&)
{
	os << "I'm just an intern. I make forms, that's all!" << std::endl;
	return (os);
}
