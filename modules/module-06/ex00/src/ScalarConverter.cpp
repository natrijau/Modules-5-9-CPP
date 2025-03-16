#include	"../include/ScalarConverter.hpp"

/*******************************************************/
/*************          convert        *****************/
/*******************************************************/

static bool	pseudoLiterals(std::string str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char : impossible\nint : impossible\nfloat : nanf\ndouble : nan" << std::endl;
		return true;
	}
	if (str == "+inf" || str == "inf" || str == "inff")
	{
		std::cout << "char : impossible\nint : impossible\nfloat : +inff\ndoubl e: +inf" << std::endl;
		return true;
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char : impossible\nint : impossible\nfloat : -inff\ndouble : -inf" << std::endl;
		return true;
	}
	return false;
}

template<typename t>
void	otherDetected(t nb, std::string str)
{
	/*	detecte si presence d'un caracter '.'	*/
	if (str.find('.') == std::string::npos || str[str.size() - 1] == '.')
		std::cout << std::fixed << std::setprecision(1);
	
	/*	verifs pour char*/
	if (nb >=0 && nb <= 126)
	{
		if (nb >= 32 && nb <= 126)
			std::cout << "char : '" << static_cast<char>(nb) << "'" << std::endl;
		else
			std::cout << "char : Non displayable" << std::endl;
	}
	else
		std::cout << "char : impossible" << std::endl;

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
	if (pseudoLiterals(str) == true)
		return;
	
	/*Char detect*/
	if (str.size() == 1 && std::isprint(str[0]))
		return (charDetected(str));
	
	/*Int detected*/
	char	*endptr;
	long	nb = std::strtol(str.c_str(), &endptr, 10); 
	if (*endptr == '\0' && (nb >= INT_MIN && nb <= INT_MAX))
		return (otherDetected(nb, str));
	
	/*float detected*/
	float	nbf = std::strtof(str.c_str(), &endptr); 
	if ((*endptr == '\0' || (*endptr == 'f' && endptr == &str[str.size() - 1])) && str[str.size() - 1] != '.')
		return (otherDetected(nbf, str));

	/*double detected*/
	double	nbdouble = std::strtod(str.c_str(), &endptr); 
	if (*endptr == '\0' && str.find('.') != std::string::npos)
		return (otherDetected(nbdouble, str));

	std::cout << "char : impossible\nint : impossible\nfloat : nanf\ndouble : nan" << std::endl;
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
