#ifndef	__BITCOINEXCHANGE_HPP__
#define	__BITCOINEXCHANGE_HPP__

#include 	<iostream>
#include 	<fstream>
#include 	<string>
#include	<map>
#include 	<cstdlib>
#include	<exception>
#include 	<iomanip>

class BitcoinExchange
{
	private:
		BitcoinExchange();
	public:
		BitcoinExchange(char *arg);
		~BitcoinExchange();
		
		void	inputFile(char *arg, std::map<std::string, float> btcExchange);
};

#endif
