#ifndef	__BUREAUCRAT_HPP__
#define	__BUREAUCRAT_HPP__

#include <iostream>
#include <exception>

class	GradeTooHighException : public	std::exception
{
	private:

		std::string	_message;

	public:
		// GradeTooHighException() throw();
		GradeTooHighException() : _message("Range to hight. Maximum grade its 1"){};
		GradeTooHighException (const GradeTooHighException& copy) throw()
		{
			this->_message = copy._message;
		};
		virtual ~GradeTooHighException() throw(){};
		GradeTooHighException &operator=(const GradeTooHighException& fix) throw()
		{
			this->_message = fix._message;
			return (*this);
		};
		virtual const	char* what() const throw()
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
		GradeTooLowException (const GradeTooLowException& copy) throw()
		{
			this->_message = copy._message;
		};
		virtual ~GradeTooLowException() throw(){};
		GradeTooLowException &operator=(const GradeTooLowException& fix) throw()
		{
			this->_message = fix._message;
			return (*this);
		};
		virtual const	char* what() const throw()
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