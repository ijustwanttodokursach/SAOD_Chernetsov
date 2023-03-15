#include "Test.h"

Test::Test() {
	cout << "Constructor" << endl;
	nCount++;
	cout << nCount << endl;
}

Test::Test(const Test& t) {
	cout << "Constructor" << endl;
	nCount++;
	cout << nCount << endl;
}

Test::~Test() {
	cout << "Destructor" << endl;
	nCount--;
	cout << nCount << endl;
}
int Test::nCount = 0;

Child::Child() {
	cout << "ChildConstructor" << endl;
}
Child::~Child() {
	cout << "ChildDestructor" << endl;
}

Agregate::Agregate() {
	cout << "AC" << endl;
}
Agregate::~Agregate() {
	cout << "AD" << endl;
}