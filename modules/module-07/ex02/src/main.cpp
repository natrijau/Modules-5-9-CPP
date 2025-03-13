#include	"../include/Array.hpp"

int     main()
{
	try {
        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = i * 2;
        }
        
        Array<int> copyArr(arr);
        copyArr[0] = 42;
        
        std::cout << "Original array: ";
        for (unsigned int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Copied array: ";
        for (unsigned int i = 0; i < copyArr.size(); i++) {
            std::cout << copyArr[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Testing out of bounds access:" << std::endl;
        std::cout << arr[10] << std::endl; // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}