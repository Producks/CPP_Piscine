#pragma once

#include <iostream>
#include <cstdint>
class Fixed
{
private:
		int32_t	fixed_value_;
		static const uint8_t fractional = 8;
public:
		//Orthodox Canonical Form
		Fixed();
		Fixed(const Fixed& rhs);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();

		//Constructor asked by subject
		Fixed(const int32_t number);
		Fixed(const float number);

		//Getter and Setter
		int32_t		getRawBits(void) const;
		void		setRawBits(int32_t const rawBits);

		//Member function asked by subject
		float		toFloat(void) const;
		int32_t		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &rhs);

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define PNK   "\x1B[38;5;206m"
#define RESET "\x1B[0m"