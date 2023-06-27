/*
 * counter.h
 */

#include <iostream>

class GenericCounter {
	int value;
public:
	GenericCounter() : value(0) { };
	virtual void up(int delta) { value += delta; };
	virtual void down(int delta) { value -= delta; };
	int get_value() { return value; };
	void set_value(int val) { value = val; };
	
	// GenericCounter c
	// c += 3
	// GenericCounter   int
	//
	// c = c + 3
	
	GenericCounter & operator+=(int delta) {
		up(delta);
		return *this;	// typeof(this) = GenericCounter *
	};
	
	GenericCounter & operator-=(int delta) {
		down(delta);
		return *this;
	};
	
	// c = 5
	// 
	GenericCounter& operator=(int val) {
		value = val;
		return *this;
	};
};

class CounterException { };

class OneStepCounter : public GenericCounter {
public:
	void up() { up(1); };
	void down() { down(1); };
	void up(int delta) {
		if (delta != 1)
			throw CounterException();
		GenericCounter::up(delta);
	};
	void down(int delta) {
		if (delta != 1)
			throw CounterException();
		GenericCounter::down(delta);
	};
	
	// OneStepCounter c;
	// c++; //c += 1;
	OneStepCounter & operator++(int) {
		up(1);
		return *this;
	};
	OneStepCounter & operator--(int) {
		down(1);
		return *this;
	};
};

class NonNegativeCounter : public OneStepCounter {
public:
	void down(int delta) {
		if (get_value() - delta < 0)
			throw CounterException();
		OneStepCounter::down(delta);
	};
};


std::ostream & operator<<(std::ostream & output, GenericCounter & c);


