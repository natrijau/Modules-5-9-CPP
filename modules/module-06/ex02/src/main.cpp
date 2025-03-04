#include	"../include/Base.hpp"
#include	"../include/A.hpp"
#include	"../include/B.hpp"
#include	"../include/C.hpp"

static Base *generate()
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

static void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Base *p -> its A type" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Base *p -> its B type" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Base *p -> its C type" << std::endl;
	else
		std::cout << "Error type" << std::endl;
}

static void identify(Base &p)
{
	try
	{
		A &aRef = dynamic_cast<A&>(p);
		std::cout << "Type of ref is : A" << std::endl;
		(void) aRef;
	}
	catch(const std::exception& e){}
	try
	{
		B &bRef = dynamic_cast<B&>(p);
		std::cout << "Type of ref is : B" << std::endl;
		(void) bRef;
	}
	catch(const std::exception& e){}
	try
	{
		C &cRef = dynamic_cast<C&>(p);
		std::cout << "Type of ref is : C" << std::endl;
		(void) cRef;
	}
	catch(const std::exception& e){}
}

int     main()
{
	for (int j = 0; j < 42; j++)
	{
		Base *Test = generate();
		if (Test == NULL)
			return (1);
		else
		{
			identify(Test);
			identify(*Test);
			delete (Test);
			std::cout << std::endl;
		}
	}
	return (0);
}
