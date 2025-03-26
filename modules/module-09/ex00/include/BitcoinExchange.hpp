#ifndef	__BITCOINEXCHANGE_HPP__
#define	__BITCOINEXCHANGE_HPP__

#include 	<iostream>
#include 	<fstream>
#include 	<string>
#include	<map>
#include 	<cstdlib>
#include 	<iomanip>

void	BitcoinExchange(char *arg)
{
	(void) arg;
	std::ifstream file("./data.csv");
    
	/*TROW ERROR*/
	//if (!file)
		//return (1);

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
    for (std::map<std::string, float>::iterator it = btcExchange.begin(); it != btcExchange.end(); ++it)
        std::cout  << "Ligne " << it->first << ": " << it->second << std::endl;



	// std::ifstream file(arg);
    
	// /*TROW ERROR*/
	// //if (!file)
	// 	//return (1);

    // std::map<std::string, float> input;
    // std::string line;
    // while (std::getline(file, line))
	// {
	// 	size_t splitComma = line.find(',');
	// 	if (splitComma != std::string::npos)
	// 	{
	// 		char *endptr;
	// 		std::string date = line.substr(0, splitComma);
	// 		double		price = std::strtod(line.substr(splitComma + 1).c_str(), &endptr);
	// 		input[date] = price;
	// 	}
	// }












};

//class BitcoinExchange : public	std::map<std::string, int>
//{
//	private:
//		double	_price;
//	public:
//		BitcoinExchange(/* args */);
//		~BitcoinExchange();
//};


#endif
