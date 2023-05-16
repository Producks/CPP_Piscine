#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
typedef struct Vector2D 
{
    Fixed x;
    Fixed y;
} Vector;

static Vector getVector(const Point& lhs, const Point& rhs) {
    Vector result;
    result.x = rhs.getX() - lhs.getX();
    result.y = rhs.getY() - lhs.getY();
    return result;
}

static int32_t getDotProduct(Vector const& vector1, Vector const& vector2){
	Fixed dotProduct;

	dotProduct = (vector1.x * vector2.x) + (vector1.y + vector2.y);
	return dotProduct.toInt();
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Vector AB = getVector(a, b);
	Vector BC = getVector(b, c);
	Vector CA = getVector(c, a);
	Vector AP = getVector(a, point);
	Vector BP = getVector(b, point);
	Vector CP = getVector(c, point);

	int32_t dotAB = getDotProduct(AB, AP);
	int32_t dotBC = getDotProduct(BC, BP);
	int32_t dotCA = getDotProduct(CA, CP);
	
	std::cout << dotAB << std::endl;
	std::cout << dotBC << std::endl;
	std::cout << dotCA << std::endl;
	if (dotAB >= 0 && dotBC >= 0 && dotCA >= 0)
		return true;
	if (dotAB < 0 && dotBC < 0 && dotCA < 0)
		return true;
	return false;
}
//https://www.mathsisfun.com/algebra/vectors-dot-product.html
