#pragma once
#include<iostream>

using namespace std;

class Test
{
public:
	Test();
	Test(const Test& t);
	~Test();
	static int nCount;
};

class Child : public Test {
public:
	Child();
	~Child();
};

class Agregate {
public:
	Test m_objTest;
	Agregate();
	~Agregate();
};

template <typename T> class AgregateT {
public:
	AgregateT() {
		cout << "AGC" << endl;
	}
	~AgregateT() {
		cout << "AGD" << endl;
	}
	T m_objTest;
};
