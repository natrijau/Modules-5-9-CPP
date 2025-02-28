#ifndef	__SCALARCONVERTER_HPP__
#define	__SCALARCONVERTER_HPP__

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <iomanip>

#include <stdlib.h>

class ScalarConverter
{
	private:
	
		ScalarConverter();
		ScalarConverter(std::string str);
		//ScalarConverter(const ScalarConverter &copy);

		static	void	convertToChar(std::string str);
		static	void	convertToInt(std::string str);
		static	void	convertToFloat(std::string str);
		static	void	convertToDouble(std::string str);
		
		ScalarConverter &operator=(const ScalarConverter& other);
	
	public:
		
		~ScalarConverter();

		static void convert(std::string str);

};

// Operator overload <<
std::ostream& operator<<(std::ostream& os, const ScalarConverter& b);

#endif