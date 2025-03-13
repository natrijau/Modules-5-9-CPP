#include	"../include/ScalarConverter.hpp"


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

//ScalarConverter::~ScalarConverter() {
	//std::cout << std::endl << "Destructor ScalarConverter called" << std::endl;
//}


/*******************************************************/
/*************          convert        *****************/
/*******************************************************/

//void ScalarConverter::impossible(std::string type, int flag)
//{
//	if (flag == 1)
//	{
//		std::cout << type << " : Non displayable" << std::endl;
//		return;
//	}
//	std::cout << type << " : impossible" << std::endl;
//}

//void ScalarConverter::convertToChar(std::string str)
//{
//	int		nb;
//	int 	count = 0;
//	bool 	allDigits = true;
	
//	if (str.length() == 1 && ((str[0] >= 32 && str[0] < 48 ) || (str[0] > 57 && str[0] <= 126 )))
//	{
//		nb = str[0];
//		std::cout << "char : '" << static_cast<char>(nb) << "'" << std::endl;
//		return;
//	}	

//	count = std::count(str.begin(), str.end(), '.');

//	if (str[str.size() - 1] == 'f')
//		str.erase(str.length() - 1);
	
//	if (str[str.size() - 1] == '.' || count > 1 || str[0] == '.')
//		return (impossible("char", 0));
//	if (str[0] == '+')
//		str.erase(str.begin());
//	if (str.find(".") != std::string::npos)
//		str.erase(str.find("."), str.size());
//	for (size_t i = 0; str[i]; i++)
//	{
//		if (!isdigit(str[i]))
//		{
//			allDigits = false;
//			break;
//		}
//	}
//	if (allDigits == false)
//		return (impossible("char", 0));
//	std::istringstream tmp(str);
//	tmp >> nb;

//	if ((nb >= 0 && nb < 127))
//	{
//		if ((nb >= 32 && nb < 48 ) || (nb > 57 && nb <= 126 ))
//		{
//			std::cout << "char : '" << static_cast<char>(nb) << "'" << std::endl;
//			return;
//		}
//		return (impossible("char", 1));
//	}
//	std::cout << "char : impossible" << std::endl;
//}

//void ScalarConverter::convertToInt(std::string str)
//{
//	int			nb;
//	int			i = 0;
//	bool 		allDigits = true;
//	std::string	copyStr = str;
	
//	if (str.length() == 1  && !isdigit(str[0]))
//	{
//		std::cout << "int : " << static_cast<int>(str[0]) << std::endl;
//		return;
//	}
	
//	if (copyStr[copyStr.size() - 1] == 'f')
//		copyStr.erase(copyStr.length() - 1);
	
//	if (copyStr[copyStr.size() - 1] == '.' || copyStr[0] == '.')
//		return (impossible("int", 0));
//	if (copyStr.find(".") != std::string::npos)
//		copyStr.erase(copyStr.find("."), copyStr.size());
//	if (str[0] == '-')
//		i++;	
//	for (; copyStr[i]; i++)
//	{
//		if (!isdigit(copyStr[i]))
//		{
//			allDigits = false;
//			break;
//		}
//	}
//	if (allDigits == false)
//		return (impossible("int", 0));
//	std::istringstream tmp(str);
//	tmp >> nb;

//	// !tmp.eof() check if !digit ||||| tmp.fail check if fail convert (ex: str > max int ...)
//	if (tmp.fail())
//		return (impossible("int", 0));
//	std::cout << "int : " << static_cast<int>(nb) << std::endl;
//}

//void ScalarConverter::convertToFloat(std::string str)
//{
//	float		nb;
//	int			i = 0;
//	bool 		allDigits = true;
//	std::string	copyStr = str;
//	int precision = str.size() - str.find('.') - 1;
//	if (precision > 4)
//		precision = 4;		
//	if (str.length() == 1  && !isdigit(str[0]))
//	{
//		std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" << std::endl;
//		return;
//	}

//	if (copyStr[copyStr.size() - 1] == 'f')
//		copyStr.erase(copyStr.length() - 1);
	
//	if (copyStr[copyStr.size() - 1] == '.' || copyStr[0] == '.')
//		return (impossible("float", 0));
//	if (copyStr.find(".") != std::string::npos)
//		copyStr.erase(copyStr.find("."), copyStr.size());
//	if (copyStr[0] == '-')
//		i++;	
//	for (; copyStr[i]; i++)
//	{
//		if (!isdigit(copyStr[i]))
//		{
//			allDigits = false;
//			break;
//		}
//	}
//	if (allDigits == false)
//		return (impossible("float", 0));
//	if (str[str.size() - 1] == 'f')
//		str.erase(str.length() - 1);
//	if (str.find(".") == std::string::npos || (str[str.size() - 1] == '0' && str[str.size() - 2] == '.'))
//		std::cout << std::fixed << std::setprecision(precision);
//	std::istringstream tmp(str);
//	tmp >> nb;
//	if (!tmp.eof() || tmp.fail())
//		return (impossible("float", 0));
//	std::cout << std::fixed << std::setprecision(precision) << "float : " << static_cast<float>(nb) <<  "f" << std::endl;
//}

//void ScalarConverter::convertToDouble(std::string str)
//{
//	double		nb;
//	bool 		allDigits = true;
//	int			i = 0;
//	std::string	copyStr = str;

//	if (str.length() == 1 && !isdigit(str[0]))
//	{
//		std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) <<std::endl;
//		return;
//	}
//	if (copyStr[copyStr.size() - 1] == 'f')
//		copyStr.erase(copyStr.length() - 1);
	
//	if (copyStr[copyStr.size() - 1] == '.' || copyStr[0] == '.')
//		return (impossible("double", 0));
//	if (copyStr.find(".") != std::string::npos)
//		copyStr.erase(copyStr.find("."), copyStr.size());
//	if (copyStr[0] == '-')
//		i++;	
//	for (; copyStr[i]; i++)
//	{
//		if (!isdigit(copyStr[i]))
//		{
//			allDigits = false;
//			break;
//		}
//	}
//	if (allDigits == false)
//		return (impossible("double", 0));
//	if (str[str.size() - 1] == 'f')
//		str.erase(str.length() - 1);
//	std::istringstream tmp(str);
//	tmp >> nb;
//	if (!tmp.eof() || tmp.fail())
//		return (impossible("double", 0));
//	int precision = str.size() - str.find('.') - 1;
//	if (precision > 8)
//		precision = 8;	
//	if (str.find(".") == std::string::npos || (str[str.size() - 1] == '0' && str[str.size() - 2] == '.'))
//		std::cout << std::fixed << std::setprecision(precision);
//	std::cout << std::fixed << std::setprecision(precision) << "double : " << static_cast<double>(nb) <<  std::endl;
//}

static bool	pseudoLiterals(std::string str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
		return true;
	}
	if (str == "+inf" || str == "inf" || str == "inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
		return true;
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
		return true;
	}
	return false;
}

//void	doubleDetected(double nb)
//{
//	if (nb < 32 || nb > 126)
//		std::cout << "char : Non displayable" << std::endl;
//	else
//		std::cout << "char : '" << static_cast<char>(nb) << "'" << std::endl;
//	std::cout << "int : '" << static_cast<int>(nb) << "'" << std::endl;
//	std::cout << "float : '" << static_cast<float>(nb) << "f'" << std::endl;
//	std::cout << "double : '" << static_cast<double>(nb) << "'" << std::endl;
//}

//void	floatDetected(float nb)
//{
//	if (nb < 32 || nb > 126)
//		std::cout << "char : Non displayable" << std::endl;
//	else
//		std::cout << "char : '" << static_cast<char>(nb) << "'" << std::endl;
//	std::cout << "int : '" << static_cast<int>(nb) << "'" << std::endl;
//	std::cout << "float : '" << static_cast<float>(nb) << "f'" << std::endl;
//	std::cout << "double : '" << static_cast<double>(nb) << "'" << std::endl;
//}

template<typename t>
void	otherDetected(t nb, std::string str)
{
	/*	detecte si presence d'un caracter '.'	*/
	if (str.find('.') == std::string::npos)
		std::cout << std::fixed << std::setprecision(1);
	
	/*	verifs pour char*/
	if (nb < 32 || nb > 126)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(nb) << "'" << std::endl;
	
	/*	verifs pour int*/
	if (nb > INT_MAX || nb < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(nb) << std::endl;
	
	/*	verifs pour float*/
	std::cout << "float : " << static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(nb) << std::endl;
}

void	charDetected(std::string str)
{
	std::cout << "char : '" << static_cast<char>(str[0]) << "'" << std::endl;
	std::cout << "int : " << static_cast<int>(str[0]) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(str[0]) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(str[0]) << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	//try
	//{
		//pseudoLiterals(str);
		///* code */
	//}
	//catch(const std::exception& e)
	//{
		//std::cerr << e.what() << '\n';
	//}
	if (pseudoLiterals(str) == true)
		return;
	
	/*Char detect*/
	if (str.size() == 1 && !isdigit(str[0]))
	{
		std::cout << "char detected \n";
		return (charDetected(str));
	}
	
	/*Int detected*/
	char	*endptr;
	long	nb = std::strtol(str.c_str(), &endptr, 10); 
	if (*endptr == '\0' && (nb >= INT_MIN && nb <= INT_MAX))
	{
		std::cout << "int detected \n";
		return (otherDetected(nb, str));
	}
	
	/*float detected*/
	float	nbf = std::strtof(str.c_str(), &endptr); 
	if ((*endptr == '\0' || (*endptr == 'f' && endptr == &str[str.size() - 1])) && str[str.size() - 1] != '.')
	{
		std::cout << "float detected \n";
		return (otherDetected(nbf, str));
	}

	/*double detected*/
	double	nbdouble = std::strtod(str.c_str(), &endptr); 
	if (*endptr == '\0'&& str[str.size() - 1] != '.')
	{
		std::cout << "double detected \n";
		return (otherDetected(nbdouble, str));
	}

	std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
}

///*******************************************************/
///*************** Assignment operator *******************/
///*******************************************************/

//ScalarConverter& ScalarConverter::operator=(const ScalarConverter& )
//{
//	return (*this);
//}

/*******************************************************/
/*************** Operator overload << *****************/
/*******************************************************/

//std::ostream& operator<<(std::ostream& os, const ScalarConverter&)
//{
//	os << "ScalarConverter" << std::endl;
//	return (os);
//}
