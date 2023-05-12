#pragma once

#include <cstdint>
class Fixed
{
private:
		int	fixed_integer;
		static const uint8_t fractional = 8;
public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();
};