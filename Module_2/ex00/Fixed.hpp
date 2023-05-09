#ifndef FIXED_HPP
# define FIXED_HPP

#include <cstdint>

class Fixed
{
private:
		int	fixed_integer;
		static const uint8_t fractional = 8;

public:
		//Default constructor
		Fixed();

		//Copy constructor
		Fixed(const Fixed& ref_class);

		//= Overload constructor
		Fixed& operator=(const Fixed& ref_class);

		//Destructor
		~Fixed();

		//Getter
		int getRawBits(void) const;

		//Setter
		void setRawBits(int const raw);

};

#endif