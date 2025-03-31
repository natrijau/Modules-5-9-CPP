#ifndef	__BITCOINEXCHANGE_HPP__
#define	__BITCOINEXCHANGE_HPP__

#include 	<iostream>
#include 	<fstream>
#include 	<string>
#include	<map>
#include 	<cstdlib>
#include 	<iomanip>
#include	<exception>

bool	allDigit(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;		
	}
	return (true);
}

bool	validDate(std::string date)
{
	char *endptr;
	int	day, month, year;
	std::string yearString = date.substr(0, 4);
	std::string monthString = date.substr(5, 2);
	std::string dayString = date.substr(8);

	if (dayString[dayString.length() - 1] != ' ')
		return false;
	else
		dayString.erase(dayString.length() - 1);

	if (!allDigit(yearString) || !allDigit(monthString) || !allDigit(dayString))
		return false;
	
	if (yearString.length() != 4 || monthString.length() > 3 || dayString.length() > 3 )
		return false;	
	
	year = std::strtod(yearString.c_str(), &endptr);
	if (year < 1000)
		return false;
	
	day = std::strtod(dayString.c_str(), &endptr);
	if (day < 0 || day > 31)
		return false;

	month = std::strtod(monthString.c_str(), &endptr);
	if (month < 0 || month > 12)
		return false;		
	
	return true;
}

void	inputFile(char *arg, std::map<std::string, float> btcExchange)
{
	std::ifstream file(arg);
	if (!file.is_open())
		throw 	std::runtime_error("Unable to open input file");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		try
		{
			size_t splitComma = line.find('|');
			if (splitComma != 11 || line[4] != '-' || line[7] != '-')
				throw 	std::runtime_error("Error: bad input => " + line);
			std::string date = line.substr(0, splitComma).c_str();
			if (!validDate(date))
				throw 	std::runtime_error("Error: bad input => " + line);
			float	number = std::strtof(line.substr(splitComma + 1).c_str(), NULL);
			if (number < 0)
				throw 	std::runtime_error("Error: not a positive number.");
			if (number > 1000)
				throw 	std::runtime_error("Error: too large a number.");
			std::map<std::string, float>::const_iterator it = btcExchange.lower_bound(date);
			if (it == btcExchange.begin() && it->first != date)
				throw 	std::runtime_error("Error: no valid exchange rate available for " + date);
			if (it == btcExchange.end() || it->first != date)
				--it;
			std::cout << date << " => " << line.substr(splitComma + 1).c_str() << " = " << number * it->second << std::endl;	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	file.close();	
}

void	BitcoinExchange(char *arg)
{
	(void) arg;
	std::ifstream file("./data.csv");
	if (!file.is_open())
		throw 	std::runtime_error("Unable to open data file");
	std::map<std::string, float> btcExchange;
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t splitComma = line.find(',');
		if (splitComma != std::string::npos)
		{
			char *endptr;
			std::string date = line.substr(0, splitComma);
			double		price = std::strtod(line.substr(splitComma + 1).c_str(), &endptr);
			btcExchange[date] = price;
		}
	}
	file.close();
	inputFile(arg, btcExchange);
};

#endif
