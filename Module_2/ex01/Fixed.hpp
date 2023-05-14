#pragma once

#include <iostream>
#include <cstdint>
class Fixed
{
private:
		int	fixed_value_;
		static const uint8_t fractional = 8;
public:
		//Orthodox Canonical Form
		Fixed();
		Fixed(const int number);
		Fixed& operator=(const Fixed& ref_class);
		~Fixed();

		//Constructor asked by subject
		Fixed(const float number);
		Fixed(const Fixed& ref_class);

		//Getter and Setter
		int 	getRawBits(void) const;
		void 	setRawBits(int const rawBits);

		//Member function asked by subject
		float 	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &ref_fixed);

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define PNK   "\x1B[38;5;206m"
#define RESET "\x1B[0m"