#include	"../include/Array.hpp"

int     main()
{
	try {
        Array<int> arr(5);
		std::cout << "Original array (int):";
        for (unsigned int i = 0; i < arr.size(); i++)
		{
            arr[i] = i + 1;
            std::cout << arr[i] << " ";
		}
        std::cout << std::endl;
        
        Array<int> copyArr(arr);
        copyArr[0] = 42;
        std::cout << "Copied array (int) after modification:";
        for (unsigned int i = 0; i < copyArr.size(); i++)
            std::cout << copyArr[i] << " ";
        std::cout << std::endl << std::endl;

		Array<std::string> str(3);
		std::cout << "Original array (std::string):";
		for (unsigned int i = 0; i < str.size(); i++)
		{
			str[i] = "void";
			std::cout << str[i] << " ";
		}
        std::cout << std::endl;
		
		str[0] = "Bonjour";
		std::cout << "Array (std::string) after modification:";
		for (unsigned int i = 0; i < str.size(); i++)
			std::cout << str[i] << " ";
        std::cout << std::endl << std::endl;
		
        std::cout << "Testing out of bounds access:" << std::endl << "Trying to access an invalid index (arr[10] does not exist) " << std::endl;
        std::cout << arr[10] << std::endl; // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}