#include	"../include/ScalarConverter.hpp"


/*******************************************************/
/************** Constructors / Destructor **************/
/*******************************************************/

ScalarConverter::ScalarConverter(){
	//std::cout << std::endl << "Constructor default ScalarConverter called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string str)
{
	convert(str);
	//std::cout << std::endl << "Constructor params ScalarConverter called" << std::endl;
}

//ScalarConverter::ScalarConverter(const ScalarConverter &copy)
//{
//	//std::cout << std::endl << "Constructor copy ScalarConverter called" << std::endl;
//}

ScalarConverter::~ScalarConverter() {
	//std::cout << std::endl << "Destructor ScalarConverter called" << std::endl;
}


/*******************************************************/
/*************          convert        *****************/
/*******************************************************/

void ScalarConverter::convertToChar(std::string str)
{
	if (str.length() == 1 && (str[0] > 0 && str[0] < 127))
	{
		if ((str[0] >= 32 && str[0] < 48 ) || (str[0] > 57 && str[0] <= 126 ))
		{
			std::cout << "char : " << str[0] << std::endl;
			return;
		}
		std::cout << "char : Non displayable" << std::endl;
		return;
	}
	std::cout << "char : impossible" << std::endl;
}

void ScalarConverter::convertToInt(std::string str)
{
	int	nb;
	std::istringstream tmp(str);
	tmp >> nb;

	// !tmp.eof() check if !digit ||||| tmp.fail check if fail convert (ex: str > max int ...)
	if (!tmp.eof() || tmp.fail())
	{
		std::cout << "int : impossible" << std::endl;
		return;
	}
	std::cout << "int : " << nb << std::endl;
}

void ScalarConverter::convertToFloat(std::string str)
{
	float	nb;
	if (str[str.size() - 1] == 'f')
		str.erase(str.length() - 1);
	std::istringstream tmp(str);
	tmp >> nb;

	if (!tmp.eof() || tmp.fail())
	{
		std::cout << "float : impossible" << std::endl;
		return;
	}
	std::cout << "float : " << nb <<  "f" << std::endl;
}

void ScalarConverter::convertToDouble(std::string str)
{
	double	nb;

	std::istringstream tmp(str);
	tmp >> nb;

	if (!tmp.eof() || tmp.fail())
	{
		std::cout << "double : impossible" << std::endl;
		return;
	}
	std::cout << "double : " << nb <<  std::endl;
}

void ScalarConverter::convert(std::string str)
{
	if (str == "nan")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
		return ;
	}
	convertToChar(str);
	convertToInt(str);
	convertToFloat(str);
	convertToDouble(str);
}

/*******************************************************/
/*************** Assignment operator *******************/
/*******************************************************/

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& )
{
	return (*this);
}

/*******************************************************/
/*************** Operator overload << *****************/
/*******************************************************/

std::ostream& operator<<(std::ostream& os, const ScalarConverter&)
{
	os << "ScalarConverter" << std::endl;
	return (os);
}
