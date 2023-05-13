#include <iostream>

using namespace std;

class Test {
private:
	int field;
public:
	Test() {}
	Test(int field) {
		this->field = field;
	}
	Test operator+=(const Test &rhs) {
		field += rhs.field;
		return *this;
	}
	friend Test operator+(const Test &lhs, const Test &rhs);
};

Test operator+(const Test &lhs, const Test &rhs) {
	Test t;
	t.field = lhs.field + rhs.field;
	return t;
}

int main(int argc, char **argv) {

	Test a(2), b(3);

	Test c = a + b;
	c += a;
	return 0;
}

