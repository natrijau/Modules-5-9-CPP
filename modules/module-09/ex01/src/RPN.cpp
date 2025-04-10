#include	"../include/RPN.hpp"

RPN::RPN(){};

RPN::RPN(char *expr)
{
	double	result = 0;
	bool	space = true;

	while (*expr == ' ')
		expr++;	
	for (size_t i = 0; expr[i]; i++)
	{
		if (expr[i] == ' ')
		{
			if (space == true)
				throw	std::runtime_error("Error");
			space = true;
			continue;
		}
		else
		{
			if (space == false)
				throw	std::runtime_error("Error");
			space = false;
		}
		if (!std::isdigit(expr[i]) && i < 2)
			throw	std::runtime_error("Error");
		else if (std::isdigit(expr[i]))
			this->_stack.push(expr[i] - '0');
		else if (expr[i] == '-' || expr[i] == '+' || expr[i] == '*' || expr[i] == '/')
		{
			if (this->_stack.size() >= 2)
			{
				result = this->_stack.top();
				this->_stack.pop();
				if (expr[i] == '-')
					result = this->_stack.top() - result;
				if (expr[i] == '+')
					result = this->_stack.top() + result;				
				if (expr[i] == '*')
					result = this->_stack.top() * result;	
				if (expr[i] == '/')
				{
					if (result == 0)
						throw	std::runtime_error("Error");
					result = this->_stack.top() / result;		
				}
				this->_stack.pop();
				this->_stack.push(result);
			}
			else
				throw	std::runtime_error("Error");
		}	
		else
			throw	std::runtime_error("Error");
	}
	if (this->_stack.size() != 1)
		throw	std::runtime_error("Error");
	std::cout << result << std::endl; 
};

RPN::~RPN(){};
