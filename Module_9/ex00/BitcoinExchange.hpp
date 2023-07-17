#pragma once
#include <iostream>
#include <map>

class BitcoinExchange {
public:
  BitcoinExchange(const std::string &file);
  BitcoinExchange(const BitcoinExchange &rhs);
  ~BitcoinExchange();

  BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void initiateCsvDataBase();
	void readInputDataBase();
	void validateString(const std::string &line);
	const std::string getClosestTime(const std::string &date);
	double getExchangeRate(const std::string &line);
	double getValue(const std::string &line) const;

private:
	std::string dataBase_;
	std::map<std::string, double> csvDataBase_;
  BitcoinExchange();
};