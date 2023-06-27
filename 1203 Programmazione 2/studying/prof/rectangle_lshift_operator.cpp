/*
 * rectangle_lshift_operator.cpp
 */
#include <iostream>

using namespace std;

class Rectangle {
private:
	// attributes
	float b, h;
public:
	// constructor
	Rectangle(float _b, float _h);
       // copy constructor
        Rectangle(const Rectangle & r);
        // Default constructor
        Rectangle();
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
	
	friend ostream& operator<< (ostream& output_stream, Rectangle& r);

};

class Square : public Rectangle {
public:
	Square(float side);
	void set_side(float side);
};


void show_dimensions(Rectangle * r)
{
	cout << "The size is " << r->get_b() << " x " << r->get_h() << endl;
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
  : b(_b), h(_h)
{
	cout << "Rect constructor " <<  endl;
}


Rectangle::Rectangle(const Rectangle& r)
    : Rectangle(r.b, r.h)
{
	cout << "Copy constructor" <<  endl;
}

Rectangle::Rectangle()
    : Rectangle(0, 0)
{
	cout << "Default constructor" <<  endl;
}


Rectangle::~Rectangle()
{
	cout << "Rect destructor " <<  endl;
}


float Rectangle::compute_area()
{
	return b * h;
}

float Rectangle::compute_perimeter()
{
	return 2 * (b + h);
}

// operator<< (cout, Rectangle r) ---> cout

ostream& operator<< (ostream& output_stream, Rectangle& r)
{
	output_stream << r.b << "x" << r.h;
	return output_stream;
}

int main(int argc, char **argv)
{
	Rectangle my_rect_1(3, 10);
	Rectangle my_rect_2(20.5, 44);
	
	//cout << "Perimeter of rect 1 = " << my_rect_1.compute_perimeter() << endl;
	
	/*
	((cout << "Perimeter of rect 1 = ") << my_rect_1.compute_perimeter()) << endl;
	(cout << my_rect_1.compute_perimeter()) << endl;
	cout << endl;
	
	cout << "Perimeter of rect 1 = ";
	cout << my_rect_1.compute_perimeter();
	cout << endl;
	
	
	int i = 3;
	
	int a = i << 2 << 3 << 4;
	a = ((i << 2) << 3) << 4;

	int temp = i << 2;
	temp = temp << 3;
	a = temp << 4;
	*/
	
	cout << my_rect_2 << endl;
	

}

