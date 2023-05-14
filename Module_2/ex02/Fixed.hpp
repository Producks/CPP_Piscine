#include <iostream>
#include <ctype.h>

class Fixed
{
private:
		int	fixed_value_;
		static const uint8_t fractional = 8;
public:
		//Orthodox Canonical Form
		Fixed();
		Fixed(const Fixed& ref_class);
		Fixed& operator=(const Fixed& ref_class);
		~Fixed();

		//Constructor asked by subject
		Fixed(const int number);
		Fixed(const float number);

		//Comparison Operators Overload
		bool operator>(const Fixed& ref_class) const;
		bool operator<(const Fixed& ref_class) const;
		bool operator>=(const Fixed& ref_class) const;
		bool operator<=(const Fixed& ref_class) const;
		bool operator==(const Fixed& ref_class) const;
		bool operator!=(const Fixed& ref_class) const;

		//Arithmetic Operators Overload
		Fixed operator+(const Fixed& ref_class) const;
		Fixed operator-(const Fixed& ref_class) const;
		Fixed operator*(const Fixed& ref_class) const;
		Fixed operator/(const Fixed& ref_class) const;

		//Increment/decrement Operators Overload

		//

		//Getter and Setter
		int 	getRawBits(void) const;
		void 	setRawBits(int const rawBits);

		//Member function asked by subject
		float 	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &ref_fixed);