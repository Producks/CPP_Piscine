#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <iomanip>

using std::cerr;
using std::cout;
using std::endl;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &file) : dataBase_(file) {
  initiateCsvDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) { *this = rhs; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs){
		dataBase_ = rhs.dataBase_;
		csvDataBase_ = rhs.csvDataBase_;
	}
  return *this;
}

void BitcoinExchange::initiateCsvDataBase() {
  std::ifstream dataBase;
  std::string line;
  dataBase.open("data.csv", std::ifstream::in);
  if (dataBase.fail())
    throw std::runtime_error("Error: couldn't open data.csv");
  while (std::getline(dataBase, line)) {
    if (line == "date,exchange_rate")
      continue;
    csvDataBase_.insert(std::make_pair(
        line.substr(0, 10), strtod(line.substr(11, 7).c_str(), NULL)));
  }
	dataBase.close();
}

const std::string BitcoinExchange::getClosestTime(const std::string &date) {
  int year = atoi(date.substr(0, 4).c_str());
  int month = atoi(date.substr(5, 2).c_str());
  int day = atoi(date.substr(8, 2).c_str());
  if (year < 2009 || month > 12 || day > 31 || !day || !month)
    throw std::runtime_error("Error: invalid date " + date);
  if (year > 2022)
    return csvDataBase_.rbegin()->first;
  std::ostringstream stream;
  std::string dateAttempt;
  do {
    day--;
    if (!day) {
      day = 31;
      month--;
      if (!month) {
        year--;
        month = 12;
      }
    }
    stream.str("");
    stream.clear();
    stream << year << "-" << std::setfill('0') << std::setw(2) << month << "-"
           << std::setfill('0') << std::setw(2) << day;
    dateAttempt = stream.str();
    if (csvDataBase_.find(dateAttempt) != csvDataBase_.end())
      return dateAttempt;
  } while (dateAttempt != "2009-01-02");
  return csvDataBase_.rbegin()->first;
}

void BitcoinExchange::validateString(const std::string &line){
	if (line[4] != '-' || line[7] != '-')
		throw std::runtime_error("Error: found bad separator for the date");
	for (int index = 0; line[index]; index++){
		if (!isdigit(line[index]) && index != 4 && index != 7)
			throw std::runtime_error("Error: found a non digit value for the date");
	}
}

double BitcoinExchange::getExchangeRate(const std::string &line){
	std::map<std::string, double>::iterator it = csvDataBase_.find(line);
	if (it != csvDataBase_.end())
		return it->second;
	validateString(line);
	return csvDataBase_.find(getClosestTime(line))->second;
}

double BitcoinExchange::getValue(const std::string &line) const{
	bool dot = false;
	int index = 0;
	if (line[index] == '-')
		throw std::runtime_error("Error: not a positive number");
	if (line[index] == '+')
		index++;
	for (; line[index]; ++index){
		if (!isdigit(line[index]) && (line[index] != '.' || dot))
			throw std::runtime_error("Error: found a non digit value");
		if (line[index] == '.')
			dot = true;
	}
	double result = strtod(line.c_str(), NULL);
	if (result > 1000)
		throw std::runtime_error("Error:  too large of a number.");
	return result;
}

void BitcoinExchange::readInputDataBase() {
  std::ifstream inputDataBase;
  std::string line;
  double exchangeRate;
  double value;

  inputDataBase.open(dataBase_.c_str(), std::ifstream::in);
  if (inputDataBase.fail())
    throw std::runtime_error("Error: couldn't open " + dataBase_);
  std::getline(inputDataBase, line);
  if (line != "date | value"){
    throw std::runtime_error("Error: invalid first line of the database ");
		inputDataBase.close();
	}
  while (std::getline(inputDataBase, line)) {
    try {
      if (line.length() < 14)
        throw std::runtime_error("Error: invalid line length");
      exchangeRate = getExchangeRate(line.substr(0, 10));
      if (line.substr(10, 3) != " | ")
        throw std::runtime_error("Error: invalid seperators");
      value = getValue(line.substr(13));
      cout << line.substr(0, 10) << " => " << value << " = "
           << value * exchangeRate << endl;
    } catch (std::exception &exception) {
      cerr << exception.what() << endl;
    }
  }
	inputDataBase.close();
}