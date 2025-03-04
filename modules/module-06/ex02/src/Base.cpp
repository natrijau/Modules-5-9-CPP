#include	"../include/Base.hpp"
#include	"../include/A.hpp"
#include	"../include/B.hpp"
#include	"../include/C.hpp"

/*******************************************************/
/************** Constructors / Destructor **************/
/*******************************************************/

//ScalarConverter::ScalarConverter(){
	//std::cout << std::endl << "Constructor default ScalarConverter called" << std::endl;
//}

//ScalarConverter::ScalarConverter(std::string str)
//{
//	convert(str);
	//std::cout << std::endl << "Constructor params ScalarConverter called" << std::endl;
//}

//ScalarConverter::ScalarConverter(const ScalarConverter &copy)
//{
	//std::cout << std::endl << "Constructor copy ScalarConverter called" << std::endl;
//}

Base::~Base() {
	//std::cout << std::endl << "Destructor Base called" << std::endl;
}

Base *generate()
{
	switch (std::rand() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			std::cout << "Invalid randomNbr" << std::endl;
			break;
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer type is : A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer type is : B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer type is : C" << std::endl;
	else
		std::cout << "Error type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &aRef = dynamic_cast<A&>(p);
		std::cout << "Ref type is : A" << std::endl;
		(void) aRef;
	}
	catch(const std::exception& e){}
	try
	{
		B &bRef = dynamic_cast<B&>(p);
		std::cout << "Ref type is : B" << std::endl;
		(void) bRef;
	}
	catch(const std::exception& e){}
	try
	{
		C &cRef = dynamic_cast<C&>(p);
		std::cout << "Ref type is : C" << std::endl;
		(void) cRef;
	}
	catch(const std::exception& e){}
}

