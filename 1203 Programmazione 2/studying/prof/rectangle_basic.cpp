/*
 * rectangle_basic.cpp
 */
 
#include <iostream>

typedef struct {
	float b, h;
} Rectangle;

void init_rectangle(Rectangle * rect, float _b, float _h)
{
	rect->b = _b;
	rect->h = _h;
}

float compute_area(Rectangle * rect)
{
	return rect->b * rect->h;
}

float compute_perimeter(Rectangle * rect)
{
	return 2 * (rect->b + rect->h);
}

int main(int argc, char **argv)
{
	Rectangle my_rect;
	init_rectangle(&my_rect, 10.5, 22.3);
	std::cout << "Perimeter = " << compute_perimeter(&my_rect) << std::endl;
	std::cout << "Area = " << compute_area(&my_rect) << std::endl;
}

