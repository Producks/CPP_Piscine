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
		Fixed& operator++();
		Fixed& operator--();
		Fixed  operator++(int);
		Fixed  operator--(int);

		//Getter and Setter
		int 	getRawBits(void) const;
		void 	setRawBits(int const rawBits);

		//Member function
		float 	toFloat(void) const;
		int		toInt(void) const;
		static Fixed&	min(Fixed& number1, Fixed& number2);
		static const Fixed& min(const Fixed& number1, const Fixed& number2);
		static Fixed&	max(Fixed& number1, Fixed& number2);
		static const Fixed& max(const Fixed& number1, const Fixed& number2);

};

std::ostream& operator<<(std::ostream& out, const Fixed &ref_fixed);