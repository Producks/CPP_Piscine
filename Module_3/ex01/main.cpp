#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <vector>
#include <unistd.h>
#include <cstdlib>

int main(void)
{
    ClapTrap gpt("GPT4");
    ScavTrap human("GPT3");
    human.beRepaired(69);
    human.guardGate();      
    human.guardGate();
}