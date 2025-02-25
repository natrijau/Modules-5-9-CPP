#ifndef	__AFORM_HPP__
#define	__AFORM_HPP__

#include 	<iostream>
#include 	<exception>
#include	"Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
	protected:

		const std::string 	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:

		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm& copy);
		virtual ~AForm();

		const std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		class	GradeTooLowException : public	std::exception
		{
			public:
				virtual const	char* what() const throw(){
					return ("grade is too low");
				};
		};
		
		class	GradeTooHighException : public	std::exception
		{
			public:
				virtual const	char* what() const throw(){
					return ("grade is too hight");
				};
		};

		void	beSigned(Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		AForm	&operator=(const AForm& other);
};
	
std::ostream&	operator<<(std::ostream& os, const AForm& other);

#endif