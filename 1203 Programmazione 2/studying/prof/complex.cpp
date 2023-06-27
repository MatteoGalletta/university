/*
 * complex.cpp
 */
 
#include <iostream>

using namespace std;

class Complex {
private:
	float real, imaginary;
public:
	Complex(float r, float i);
	Complex();
	Complex(const Complex & c);
	friend ostream& operator<<(ostream& output_stream, Complex & c);
	Complex operator+(Complex & rhs);
	Complex operator+(double rhs);
	Complex operator-(Complex & rhs);
	Complex operator-(double rhs);
	Complex operator*(Complex & rhs);
	Complex operator/(Complex & rhs);
};

ostream& operator<<(ostream& output_stream, Complex & c)
{
	output_stream << c.real;
	if (c.imaginary < 0)
		output_stream << c.imaginary;
	else
		output_stream << "+" << c.imaginary;
	output_stream << "i";
	return output_stream;
}

Complex Complex::operator+(Complex &rhs)
{
	// risultato.real = this->real + rhs.real;
	// risultato.imaginarty = this->imaginray + rhs.imaginary;
	Complex result(real + rhs.real, imaginary + rhs.imaginary);
	return result;
}

Complex Complex::operator+(double rhs)
{
	Complex result(real + rhs, imaginary);
	return result;
}

Complex Complex::operator-(Complex &rhs)
{
	// risultato.real = this->real - rhs.real;
	// risultato.imaginarty = this->imaginray - rhs.imaginary;
	Complex result(real - rhs.real, imaginary - rhs.imaginary);
	return result;
}

Complex Complex::operator-(double rhs)
{
	Complex result(real - rhs, imaginary);
	return result;
}

Complex Complex::operator*(Complex & rhs)
{
	Complex result(real*rhs.real - imaginary*rhs.imaginary,
			real*rhs.imaginary + imaginary*rhs.real);
	return result;
}

Complex Complex::operator/(Complex & rhs)
{
	float den = rhs.real * rhs.real + rhs.imaginary * rhs.imaginary;
	
	Complex result( (real*rhs.real + imaginary*rhs.imaginary) / den,
			(imaginary*rhs.real - real*rhs.imaginary) / den );
	return result;
}

Complex::Complex(float r, float i)
  : real(r), imaginary(i)
{
}

Complex::Complex()
  : Complex(0,0)
{
}

Complex::Complex(const Complex & c)
  : Complex(c.real, c.imaginary)
{
}

int main(int argc, char ** argv)
{
	Complex a, b(1,2), c(3,4);
	
	cout << a << ", " << b << ", " << c << endl;
	
	Complex d = b + c;
	// Complex d = b.operator+(c);
	cout << d << endl;
	
	d = b - c;
	cout << d << endl;
	
	d = c + 3;
	cout << d << endl;
	
	d = c - 3.5;
	cout << d << endl;
	
	d = b * c;
	cout << d << endl;

	d = b / c;
	cout << d << endl;
}


