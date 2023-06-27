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

template <typename T> class SetDuplicates {
protected: // visibili anche alle classi figlie
	T * data;
	int size;
public:
	SetDuplicates() : size(0) { };
	SetDuplicates(SetDuplicates& s) {
		size = s.size;
		data = new T[size];
		for (int i = 0; i < size;i++) {
			data[i] = s.data[i];
		}
	};
	~SetDuplicates() {
		if (size > 0)
			delete [] data;
	};
	
	virtual void add(T elem) {
		T * new_data = new T[size + 1];
		for (int i = 0; i < size;i++) {
			new_data[i] = data[i];
		}
		new_data[size] = elem;
	
		if (size > 0)
			delete [] data;
		data = new_data;
		size++;
	};
	
	bool remove(T elem) {
		int i;
		for (i = 0; i < size;i++) {
			if (data[i] == elem)
				break;
		}
	
		if (i == size)
			return false;
		
		size--;
		if (size > 0) {
			for (int j = i; j < size;j++) {
				data[j] = data[j + 1];
			}
		
			T * new_data = new T[size];
			for (int i = 0; i < size;i++) {
				new_data[i] = data[i];
			}
		
			delete [] data;
			data = new_data;
		}
		else
			delete [] data;
		return true;
	}
	
	bool find(T elem) {
		for (int i = 0; i < size;i++) {
			if (data[i] == elem)
				return true;
		}
		return false;
	};
	
	void show() {
		for (int i = 0; i < size;i++) {
			cout << data[i] << endl;
		}
	};
	
	//friend ostream& operator<<(ostream& output_stream, SetDuplicates& s);
	SetDuplicates& operator+=(T elem) {
		this->add(elem);
		return *this;
	};
	SetDuplicates& operator-=(T elem) {
		remove(elem);
		return *this;
	};
	//SetDuplicates operator+(SetDuplicates & rhs);
	//SetDuplicates operator-(SetDuplicates & rhs);
	
	T operator[](int index) { 
		if (index < 0)
			throw UnderflowError();
		if (index >= size)
			throw OverflowError();
		return data[index]; 
	};
	int length() { return size; };
};

