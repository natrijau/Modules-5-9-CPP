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
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:

		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& copy);
		~Form();

		const std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		class	GradeTooLowException : public	std::exception
		{
			public:
				virtual const	char* what() const throw(){
					return ("his grade is lower than _gradeToSign");
				};
		};
		
		class	GradeTooHighException : public	std::exception
		{
			public:
				virtual const	char* what() const throw(){
					return ("noteToSigned is too low");
				};
		};

		void	beSigned(Bureaucrat& bureaucrat);

		Form	&operator=(const Form& other);
};
	
std::ostream&	operator<<(std::ostream& os, const Form& other);

#endif