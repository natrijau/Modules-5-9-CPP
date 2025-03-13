#include	"../include/Bureaucrat.hpp"	
#include	"../include/RobotomyRequestForm.hpp"	
#include	"../include/PresidentialPardonForm.hpp"	
#include	"../include/ShrubberyCreationForm.hpp"	

static	int i = 1;

void	robotization()
{
	std::cout << "/*******************************************************/" << std::endl;			
	std::cout << "\t\t"<< i << " test in robotization()" << std::endl;
	std::cout << "/*******************************************************/" << std::endl;			
	i++;	
	try
	{
		RobotomyRequestForm president("Bender");
		Bureaucrat bureaucrat("Homer", 1);
		bureaucrat.signForm(president);
		president.execute(bureaucrat);
		president.execute(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Shrubbery()
{
	std::cout << "/*******************************************************/" << std::endl;			
	std::cout << "\t\t"<< i << " test in Shrubbery()" << std::endl;
	std::cout << "/*******************************************************/" << std::endl;			
	i++;
	try
	{
		ShrubberyCreationForm president("Michel Dumas");
		Bureaucrat bureaucrat("Kong", 1);
		bureaucrat.signForm(president);
		president.execute(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	PardonFom()
{
	std::cout << "/*******************************************************/" << std::endl;			
	std::cout << "\t\t"<< i << " test in PardonFom()" << std::endl;
	std::cout << "/*******************************************************/" << std::endl;			
	i++;
	try
	{
		PresidentialPardonForm president("Michel Dumas");
		Bureaucrat bureaucrat("Kong", 1);
		bureaucrat.signForm(president);
		president.execute(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int     main(void)
{
	try
	{
		PardonFom();
		std::cout << std::endl;
		Shrubbery();
		std::cout << std::endl;
		robotization();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}