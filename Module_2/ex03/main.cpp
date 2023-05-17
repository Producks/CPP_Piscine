#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point a(1, 1);
	Point b(5, 5);
	Point c(3, 3);
	Point point(3, 4);
	bool	result;

	result = bsp(a, b, c, point);
	if (result == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	return 0;
}