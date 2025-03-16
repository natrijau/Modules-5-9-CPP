#include	"../include/Base.hpp"
#include	"../include/A.hpp"
#include	"../include/B.hpp"
#include	"../include/C.hpp"

int     main()
{
	for (int j = 0; j < 5; j++)
	{
		Base *Test = generate();
		if (Test == NULL)
			return (1);
		else
		{
			std::cout << "	Identify of the object pointed -> void identify(Base *p)" << std::endl;
			identify(Test);
			std::cout << std::endl;
			std::cout << "	Identify of the object referenced -> void identify(Base &p)" << std::endl;
			identify(*Test);
			delete (Test);
			std::cout << std::endl;
		}
	}
	return (0);
}
