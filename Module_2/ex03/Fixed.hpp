#pragma once

#include <iostream>
#include <ctype.h>
class Fixed
{
private:
		int32_t	fixed_number_;
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

		//Comparison Operators Overload
		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;

		//Arithmetic Operators Overload
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		//Increment/decrement Operators Overload
		Fixed& operator++();
		Fixed& operator--();
		Fixed  operator++(int);
		Fixed  operator--(int);

		//Getter and Setter
		int32_t 	getRawBits(void) const;
		void 		setRawBits(int32_t const rawBits);

		//Member function
		float				toFloat(void) const;
		int32_t				toInt(void) const;
		static Fixed&		min(Fixed& lhs, Fixed& rhs);
		static const Fixed&	min(const Fixed& lhs, const Fixed& rhs);
		static Fixed&		max(Fixed& lhs, Fixed& rhs);
		static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);

};
std::ostream& operator<<(std::ostream& out, const Fixed &rhs);