#ifndef	__PRESIDENTIALPARDONFORM_HPP__
#define	__PRESIDENTIALPARDONFORM_HPP__

#include 	<iostream>
#include 	<exception>
#include	"Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public	AForm
{
	private:

		const std::string 	_target;

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		const std::string getTarget() const;

		void	execute(Bureaucrat const & executor) const;

		PresidentialPardonForm	&operator=(const PresidentialPardonForm& other);
};
	
std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& other);

#endif