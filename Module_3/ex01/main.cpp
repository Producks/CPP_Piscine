#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <vector>
#include <unistd.h>

int main(void)
{
    std::vector<std::string> strings;
    strings.push_back("\e[40m  ");
    strings.push_back("\e[41m  ");
    strings.push_back("\e[42m  ");
    strings.push_back("\e[43m  ");
    strings.push_back("\e[44m  ");
    strings.push_back("\e[45m  ");
    strings.push_back("\e[46m  ");
    strings.push_back("\e[47m  ");
    strings.push_back("\e[48m  ");
    strings.push_back("\e[49m  ");

    std::srand(std::time(0));

    while (true)
    {
        for (int i = 0; i < 100; i++) // Print 5 random colors
        {
            int randomIndex = std::rand() % strings.size();
            std::cout << strings[randomIndex];
			usleep(500);
        }

        std::cout << "\r";
    }

    return 0;
}