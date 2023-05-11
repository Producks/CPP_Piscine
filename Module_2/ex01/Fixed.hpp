#pragma once

#include <cstdint>
class Fixed
{
private:
		Fixed();
		static const uint8_t fractional = 8;
public:
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();
};