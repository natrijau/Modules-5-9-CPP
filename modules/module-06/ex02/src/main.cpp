#include	"../include/Base.hpp"
#include	"../include/A.hpp"
#include	"../include/B.hpp"
#include	"../include/C.hpp"

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
