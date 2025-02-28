#ifndef	__SCALARCONVERTER_HPP__
#define	__SCALARCONVERTER_HPP__

#include <iostream>
#include <sstream>

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
		
	public:
		
		~ScalarConverter();
		static void convert(std::string str);

		ScalarConverter &operator=(const ScalarConverter& other);
};

// Operator overload <<
std::ostream& operator<<(std::ostream& os, const ScalarConverter& b);

#endif