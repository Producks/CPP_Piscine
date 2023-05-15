#ifndef FIXED_HPP
# define FIXED_HPP

#include <cstdint>

class Fixed
{
private:
		int32_t	fixed_integer;
		static const uint8_t fractional = 8;

public:
		//Orthodox Canonical Form
		Fixed();
		Fixed(const Fixed& rhs);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();

		//Getter and Setter
		int32_t getRawBits(void) const;
		void setRawBits(int32_t const raw);
};

#endif