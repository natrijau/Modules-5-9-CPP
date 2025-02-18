#ifndef	__FORM_HPP__
#define	__FORM_HPP__

#include <iostream>
#include <exception>
#include	"Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	private:

		const std::string 	_name;
		bool				_signed;
		const int			_noteToSign;
		const int			_noteToExec;

	public:

		Form();
		Form(std::string name, int noteToSign, int noteToExec);
		~Form();

		const std::string getName() const;
		bool getSigned() const;
		int getNote() const;
		int getNoteToExec() const;

		class GradeTooHighException;
		class GradeTooLowException;

		void	beSigned(Bureaucrat& bureaucrat);
		Form	&operator=(const Form& other);
};
	
std::ostream&	operator<<(std::ostream& os, const Form& other);

#endif