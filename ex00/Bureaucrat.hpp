#ifndef	__BUREAUCRAT_HPP__
#define	__BUREAUCRAT_HPP__

#include <iostream>
#include <exception>

class	GradeTooHighException : public	std::exception
{
	private:

		std::string	_message;

	public:

		GradeTooHighException() : _message("Range to hight. Maximum grade its 1"){};
		const	char* what() const throw()
		{
        	return _message.c_str();
    	};
};

class	GradeTooLowException : public	std::exception
{
	private:

		std::string	_message;

	public:

		GradeTooLowException() : _message("Range to low. Minimum grade its 150"){};
		const	char* what() const throw()
		{
        	return _message.c_str();
    	};
};

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

		// GradeTooHighException* test;
		// GradeTooLowException();
		// void	GradeTooHighException();
		// void	GradeTooLowException();

		void decrementGrade();
		void incrementGrade();

		Bureaucrat &operator=(const Bureaucrat& other);
};


// Operator overload <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif