/*
 * rectangle_object.cpp
 */
#include <iostream>

class Rectangle {
private:
	// attributes
	float b, h;
public:
	// methods
	void init(float _b, float _h);
	float compute_area();
	float compute_perimeter();
};

void Rectangle::init(float _b, float _h)
{
	b = _b;
	h = _h;
}

float Rectangle::compute_area()
{
	return b * h;
}

float Rectangle::compute_perimeter()
{
	return 2 * (b + h);
}

int main(int argc, char **argv)
{
	Rectangle my_rect_1, my_rect_2;
	my_rect_1.init(3, 10);
	my_rect_2.init(20.5, 44);
	std::cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << std::endl;
	std::cout << "Area of rect 1 = " << my_rect_1.compute_area() << std::endl;
	std::cout << "Perimeter of rect 2 = " << my_rect_2.compute_perimeter() << std::endl;
	std::cout << "Area of rect 2 = " << my_rect_2.compute_area() << std::endl;
}

