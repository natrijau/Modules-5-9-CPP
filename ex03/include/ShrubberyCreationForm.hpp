#ifndef	__SHRUBBERYCREATIONFORM_HPP__
#define	__SHRUBBERYCREATIONFORM_HPP__

#include 	<iostream>
#include 	<exception>
#include 	<fstream>
#include	"Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public	AForm
{
	private:

		const std::string 	_target;

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		const std::string getTarget() const;

		void	execute(Bureaucrat const & executor) const;

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm& other);
};
	
std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& other);

#endif