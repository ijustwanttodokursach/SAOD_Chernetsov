#include <iostream>
#include"Test.h"

using namespace std;

//Test g;

void foo(Test t) {
	cout << "Running" << endl;
}

int main()
{
	//cout << "Before" << endl;
	//Test t;
	//cout << "After" << endl;
	//Test* p = new Test;
	//delete p;

	/*Test* y = new Test[3];
	delete[] y;*/
	/*Test z;
	foo(z);*/
	//Child cc;

	//Agregate AG;

	//AgregateT <Test> A;
	AgregateT <Child> A;
}