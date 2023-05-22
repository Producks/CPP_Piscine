#pragma once

#include <iostream>
#include <ctype.h>

class ClapTrap
{
private:
		ClapTrap();

		std::string _name;
		int32_t 	_hitPoint;
		int32_t 	_energyPoint;
		int32_t 	_attackDamage;

		bool canPerformAction() const;
public:
		ClapTrap(const std::string& nameToSet);
		ClapTrap(const ClapTrap& rhs);
		ClapTrap& operator=(const ClapTrap& rhs);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define PNK   "\x1B[38;5;206m"
#define BRED  "\x1B[91m"
#define BGRE  "\x1B[92m"
#define BACKGROUNDRED "\x1B[41m"
#define RESET "\x1B[0m"
#define Bold "\x1B[1m"
#define Underline "\x1B[4m"
#define Blink "\x1B[5m"
#define Reverse "\x1B[7m"