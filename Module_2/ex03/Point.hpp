#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);
class Point
{
private:
		Fixed const _x;
		Fixed const _y;
public:
		//Orthodox Canonical Form
		Point();
		Point(const Point& classRef);
		Point& operator=(const Point& classRef);
		~Point();

		//Constructor asked by subject
		Point(const float x, const float y);

		//Getter and Setter
		const Fixed& getX() const;
		const Fixed& getY() const;
};

// cross product
// - down or + up