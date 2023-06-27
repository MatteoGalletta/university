/*
 * rectangle_constructor.cpp
 */
#include <iostream>

class Rectangle {
private:
	// attributes
	float b, h;
public:
	// constructor
	Rectangle(float _b, float _h);
	// destructor
	~Rectangle();
	
	// methods
	float compute_area();
	float compute_perimeter();
};


Rectangle::Rectangle(float _b, float _h)
{
	std::cout << "Rect constructor " <<  std::endl;
	b = _b;
	h = _h;
}


Rectangle::~Rectangle()
{
	std::cout << "Rect destructor " <<  std::endl;
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
	Rectangle my_rect_1(3, 10);
	Rectangle my_rect_2(20.5, 44);
	std::cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << std::endl;
	std::cout << "Area of rect 1 = " << my_rect_1.compute_area() << std::endl;
	std::cout << "Perimeter of rect 2 = " << my_rect_2.compute_perimeter() << std::endl;
	std::cout << "Area of rect 2 = " << my_rect_2.compute_area() << std::endl;


	Rectangle * my_rect_3;
	my_rect_3 = new Rectangle(30,40);
	std::cout << "Perimeter of rect 3 = " << my_rect_3->compute_perimeter() << std::endl;
	std::cout << "Area of rect 3 = " << my_rect_3->compute_area() << std::endl;
	delete my_rect_3;
	
}

