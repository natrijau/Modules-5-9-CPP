#include	"../include/Form.hpp"

/*******************************************************/
/********************* Exceptions **********************/
/*******************************************************/

class	Form::GradeTooLowException : public	std::exception
{
	private:
		std::string _message;
	public:
		//GradeTooLowException(){};
		GradeTooLowException(std::string name) : _message(name + " : note too low. Minimum rating is 150"){};
		virtual ~GradeTooLowException() throw(){};
		virtual const	char* what() const throw()
		{
			return (_message.c_str());
        	//return (" : Range to low. Minimum grade its 150");
    	};
};

class	Form::GradeTooHighException : public	std::exception
{
	private:
		std::string _message;	
	public:
		//GradeTooHighException(){};
		GradeTooHighException(std::string name) : _message(name + " : note too high. Maximum rating is 1"){};
		virtual ~GradeTooHighException() throw(){};
		virtual const	char* what() const throw()
		{
			return (_message.c_str());
        	//return (" : Range to hight. Maximum grade its 1");
    	};
};

/*******************************************************/
/************** Constructors / Destructor **************/
/*******************************************************/

Form::Form() : _name("default"), _signed(false), _noteToSign(150), _noteToExec(150){};

Form::Form(std::string name, int noteToSign, int noteToExec) : _name("default"), _signed(false), _noteToSign(noteToSign), _noteToExec(noteToExec){
	std::cout << std::endl << "Constructor with params called" << std::endl;
	if (_noteToSign < 1)
		throw GradeTooHighException(this->getName());
	else if (_noteToSign > 150)
		throw GradeTooLowException(this->getName());
	
	if (_noteToExec < 1)
		throw GradeTooHighException(this->getName());
	else if (_noteToExec > 150)
		throw GradeTooLowException(this->getName());	
}

Form::Form(const Form &copy) : _name(copy.getName()), _signed(copy.getSigned()), _noteToSign(copy.getNote()), _noteToExec(copy.getNoteToExec()){
	std::cout << std::endl << "Constructor default Form called" << std::endl;
}

Form::~Form() {
	std::cout << std::endl << "Destructor Form called" << std::endl;
}

/*******************************************************/
/********************* Getters *************************/
/*******************************************************/

const std::string	Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const{
	return (this->_signed);
}

int Form::getNote() const{
	return (this->_noteToSign);
}

int Form::getNote() const{
	return (this->_noteToExec);
}

/*******************************************************/
/*************** Assignment operator *******************/
/*******************************************************/

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

/*******************************************************/
/*************** Operator overload << *****************/
/*******************************************************/

std::ostream& operator<<(std::ostream& os, const Form& b)
{
	os << b.getName() << ", Form grade : " << b.getGrade();
	return (os);
}
