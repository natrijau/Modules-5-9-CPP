#include	"../include/BitcoinExchange.hpp"

static bool	allDigit(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
		return false;
	}
	return (true);
}

static bool isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0)
			return true;
		else if (year % 400 == 0)
			return true;
		else
			return false;
	}
	return false;
}

static bool	validDate(std::string date)
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

	month = std::strtod(monthString.c_str(), &endptr);
	if (month < 1 || month > 12)
		return false;

	day = std::strtod(dayString.c_str(), &endptr);
	if (day < 1 || day > 31)
		return false;

	const int daysInMonth[] = {
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

	int maxDay = daysInMonth[month];
	if (month == 2 && isLeapYear(year))
		maxDay = 29;

	if (day > maxDay)
		return false;

	return true;
}


BitcoinExchange::BitcoinExchange(char *arg)
{
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
}

void BitcoinExchange::inputFile(char *arg, std::map<std::string, float> btcExchange)
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
			char *endptr;
			double	number = std::strtod(line.substr(splitComma + 1).c_str(), &endptr);
			if (*endptr != '\0')
				throw 	std::runtime_error("Error: bad input => " + line);
			if (number < 0)
				throw 	std::runtime_error("Error: not a positive number.");
			if (number > 1000)
				throw 	std::runtime_error("Error: too large a number.");
			std::map<std::string, float>::const_iterator it = btcExchange.lower_bound(date);
			if (it == btcExchange.begin() && it->first != date)
			throw 	std::runtime_error("Error: no valid exchange rate available for " + date);
			if (it == btcExchange.end() || it->first != date)
			--it;
			std::cout << std::fixed << std::setprecision(2) << date << " => " << line.substr(splitComma + 1).c_str() << " = " << number * it->second << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	file.close();	
}

BitcoinExchange::~BitcoinExchange(){};