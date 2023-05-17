#include <iostream>
#include <ctype.h>

class ClapTrap
{
private:
		std::string name;
		uint8_t hitPoint;
		uint8_t energyPoint;
		uint8_t attackDamage;
public:
		ClapTrap();
		ClapTrap(const ClapTrap& rhs);
		ClapTrap& operator=(const ClapTrap rhs);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};