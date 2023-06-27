/*
 * set.h
 */

#include <iostream> 
#include <exception>
 
using namespace std;

class RangeError : public exception {
public:
	RangeError() : exception() {};
	virtual const char * getMessage() { return "Range Error"; };
};

class UnderflowError : public RangeError {
public:
	UnderflowError() : RangeError() {};
	const char * getMessage() { return "Index < 0 Error"; };
};

class OverflowError : public RangeError {
public:
	OverflowError() : RangeError() {};
	const char * getMessage() { return "Index >= size Error"; };
};

class SetDuplicates {
protected: // visibili anche alle classi figlie
	int * data;
	int size;
public:
	SetDuplicates();
	SetDuplicates(SetDuplicates& s);
	~SetDuplicates();
	virtual void add(int elem);
	bool remove(int elem);
	bool find(int elem);
	friend ostream& operator<<(ostream& output_stream, SetDuplicates& s);
	SetDuplicates& operator+=(int elem) {
		this->add(elem);
		return *this;
	};
	SetDuplicates& operator-=(int elem) {
		remove(elem);
		return *this;
	};
	SetDuplicates operator+(SetDuplicates & rhs);
	SetDuplicates operator-(SetDuplicates & rhs);
	
	int operator[](int index) { 
		if (index < 0)
			throw UnderflowError();
		if (index >= size)
			throw OverflowError();
		return data[index]; 
	};
	int length() { return size; };
};

class Set : public SetDuplicates {
public:
	void add(int elem);
	Set operator+(Set & rhs);
};


