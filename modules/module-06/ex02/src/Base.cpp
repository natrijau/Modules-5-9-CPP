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

//static Base *generate()
//{
//	int randomNumber  = std::rand() % 3 + 1;	// 1 >= 100;

//	switch (randomNumber)
//	{
//		case 1:
//			return (new A);
//		case 2:
//			return (new B);
//		case 3:
//			return (new C);
//		default:
//			std::cout << "Invalid randomNbr" << std::endl;
//			break;
//	} 
//}

//static void identify(Base *p)
//{
//	if (static_cast<A*>(p) != nullptr)
//		std::cout << "The real type of the object is : " << static_cast<A*>(p) << std::endl;
//	else if (static_cast<B*>(p) != nullptr)
//		std::cout << "The real type of the object is : " << static_cast<A*>(p) << std::endl;
//	else if (static_cast<C*>(p) != nullptr)
//		std::cout << "The real type of the object is : " << static_cast<A*>(p) << std::endl;
//	else
//		std::cout << "Error type" << std::endl;
//}

//static void identify(Base &p)
//{
//	(void)p;
//	//static_cast<A&>(p);
//}

