#ifndef	__ROBOTOMYREQUESTFORM_HPP__
#define	__ROBOTOMYREQUESTFORM_HPP__

#include 	<iostream>
#include 	<exception>
#include	"Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public	AForm
{
	private:

		const std::string 	_target;

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		const std::string getTarget() const;

		void	execute(Bureaucrat& bureaucrat);

		RobotomyRequestForm	&operator=(const RobotomyRequestForm& other);
};
	
std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& other);

#endif