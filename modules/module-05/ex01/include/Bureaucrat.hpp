#ifndef	__BUREAUCRAT_HPP__
#define	__BUREAUCRAT_HPP__
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

#include <iostream>
#include <exception>
#include	"Form.hpp"

class Form;

class Bureaucrat
{
	private:

		const std::string 	_name;
		int					_range;

	public:

		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(const std::string name, int range);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		class	GradeTooHighException;
		class	GradeTooLowException;

		void	decrementGrade();
		void	incrementGrade();
		void	signForm(Form &form);

		Bureaucrat	&operator=(const Bureaucrat& other);
};

// Operator overload <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif