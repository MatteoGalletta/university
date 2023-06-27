/*
 * rectangle_inheritance.cpp
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
	
	float get_b() { return b; };
	float get_h() { return h; };
	void get_dimension(float & _b, float & _h) {
		_b = b;
		_h = h;
	};

	void set_b(float _b) { b = _b; };
	void set_h(float _h) { h = _h; };
	void set_dimension(float _b, float _h) {
		b = _b;
		h = _h;
	};
	
	void show();
};

class Square : public Rectangle {
public:
	Square(float side);
	void set_side(float side);
};


void show_dimensions(Rectangle * r)
{
	std::cout << "The size is " << r->get_b() << " x " << r->get_h() << std::endl;
}

Square::Square(float side)
    : Rectangle(side, side) 	// invocation of the parent-class constructor
{
	//... Square-specific
}

void Square::set_side(float side)
{
	set_dimension(side, side);
}


void Rectangle::show()
{
	show_dimensions(this);	// type this e' Rectangle *
}

Rectangle::Rectangle(float _b, float _h)
{
	std::cout << "Rect constructor " <<  std::endl;
	this->b = _b;
	this->h = _h;
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
	show_dimensions(&my_rect_1);

	Rectangle * my_rect_3;
	my_rect_3 = new Rectangle(30,40);
	std::cout << "Perimeter of rect 3 = " << my_rect_3->compute_perimeter() << std::endl;
	std::cout << "Area of rect 3 = " << my_rect_3->compute_area() << std::endl;
	std::cout << "The size of rect 3 is " << my_rect_3->get_b() << " x " << my_rect_3->get_h() << std::endl;
	float base, height;
	my_rect_3->get_dimension(base, height);
	std::cout << "The size of rect 3 is " << base << " x " << height << std::endl;
	my_rect_3->show();
	delete my_rect_3;
	
	my_rect_1.set_dimension(3,4);
	std::cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << std::endl;
	
	Square q(30);
	std::cout << "Area of square " << q.compute_area() << std::endl;

}

