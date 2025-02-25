#include	"../include/Bureaucrat.hpp"	
#include	"../include/RobotomyRequestForm.hpp"	
#include	"../include/PresidentialPardonForm.hpp"	
#include	"../include/ShrubberyCreationForm.hpp"	
#include	"../include/Intern.hpp"	

static	int i = 1;

void	internMakeForm()
{
	std::cout << "/*******************************************************/" << std::endl;			
	std::cout << "\t\t"<< i << " test in internMakeForm()" << std::endl;
	std::cout << "/*******************************************************/" << std::endl;			
	i++;
	try
	{
		Intern	intern;
		AForm	*form;

		form = intern.makeForm("shrub creation", "bender");
		Bureaucrat bureaucrat("boss", 1);
		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		delete(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	internWrongFormName()
{
	std::cout << "/*******************************************************/" << std::endl;			
	std::cout << "\t\t"<< i << " test in internWrongFormName()" << std::endl;
	std::cout << "/*******************************************************/" << std::endl;			
	i++;
	try
	{
		Intern	intern;
		AForm	*form;

		form = intern.makeForm("wrong form name", "bender");
		Bureaucrat bureaucrat("boss", 1);
		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		delete(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	copyIntern()
{
	std::cout << "/*******************************************************/" << std::endl;			
	std::cout << "\t\t"<< i << " test in copyIntern()" << std::endl;
	std::cout << "/*******************************************************/" << std::endl;			
	i++;
	try
	{
		const Intern	intern;
		Intern	copy(intern);

		std::cout << intern << "my memory address : " << &intern << std::endl;
		std::cout << copy << "my memory address : " << &copy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	try
	{
		copyIntern();
		std::cout << std::endl;
		internMakeForm();
		std::cout << std::endl;
		internWrongFormName();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}