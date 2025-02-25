#ifndef	__BUREAUCRAT_HPP__
#define	__BUREAUCRAT_HPP__

#include <iostream>
#include <exception>


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

		class GradeTooHighException;
		class GradeTooLowException;

		void decrementGrade();
		void incrementGrade();

		Bureaucrat &operator=(const Bureaucrat& other);
};


// Operator overload <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif