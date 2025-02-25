#ifndef	__INTERN_HPP__
#define	__INTERN_HPP__

#include 	<iostream>
#include 	<exception>
#include	"AForm.hpp"
#include	"RobotomyRequestForm.hpp"	
#include	"PresidentialPardonForm.hpp"	
#include	"ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
	public:

		Intern();
		Intern(const Intern &copy);
		~Intern();

		class	InternException;

		AForm	*makeForm(std::string nameForm, std::string target);

		Intern	&operator=(const Intern&);
};

// Operator overload <<
std::ostream& operator<<(std::ostream& os, const Intern&);

#endif