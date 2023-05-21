#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    //ClapTrap gpt("GPT4");
    ScavTrap human("GPT3");
    human.beRepaired(69);
    human.guardGate();      
    human.guardGate();
	for (int i = 0; i < 50; i++)
		human.takeDamage(10);
// 	for (int i = 0; i < 50; i++)
// 		gpt.takeDamage(1);
// 	gpt.attack("LOL");
}