#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>

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

		void	GradeTooHighException();
		void	GradeTooLowException();

		void decrementGrade();
		void incrementGrade();

		Bureaucrat &operator=(const Bureaucrat& other);
};

// Operator overload <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif