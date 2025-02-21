#ifndef	__INTERN_HPP__
#define	__INTERN_HPP__

#include 	<iostream>
#include 	<exception>
#include	"AForm.hpp"

class AForm;

class Intern
{
	public:

		Intern();
		Intern(const Intern &copy);
		~Intern();

		//class	GradeTooHighException;
		//class	GradeTooLowException;

		AForm	*makeForm(std::string nameForm, std::string target);

		Intern	&operator=(const Intern& other);
};

// Operator overload <<
std::ostream& operator<<(std::ostream& os, const Intern& b);

#endif