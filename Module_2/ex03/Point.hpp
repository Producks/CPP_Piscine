#include "Fixed.hpp"

#include <ctype.h>
class Point
{
private:
		Fixed const x_axis;
		Fixed const y_axis;
public:
		//Orthodox Canonical Form
		Point();
		Point(const Point& rhs);
		Point& operator=(const Point& rhs); //private maybe?
		~Point();

		//Constructor asked by subject
		Point(const float x, const float y);

		//Getter and Setter
		const Fixed& getX() const;
		const Fixed& getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);


// cross product
// - down or + up