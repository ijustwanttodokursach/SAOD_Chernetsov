#include <iostream>
#include<set>
#include <unordered_set>
#include<random>

using namespace std;
set<int> operator *(set<int> &a, set<int> &b) {
	set<int> res;
	for (int t : a) {
		for (int y : b) {
			if (t == y) res.insert(t);
		}
	}
	return res;
}
unordered_set<int> operator *(unordered_set<int>& a, unordered_set<int>& b) {
	unordered_set<int> res;
	for (int t : a) {
		for (int y : b) {
			if (t == y) res.insert(t);
		}
	}
	return res;
}

void print(set<int> a) {
	for (int t : a) {
		cout << t<< " ";
	}
}
void print(unordered_set<int> a) {
	for (int t : a) {
		cout << t << " ";
	}
}

int main()
{
	set<int> a;
	for (int i = 0; i < 12; i++) {
		a.insert(rand()%10);
	}
	set<int> b;
	for (int i = 0; i < 12; i++) {
		int rnd = rand() % 10;
		b.insert(rnd);
	}
	print(a);
	cout << endl;
	print(b);
	cout << endl;
	print(a*b);

	cout << endl;

	unordered_set<int> a1;
	for (int i = 0; i < 12; i++) {
		a1.insert(rand() % 10);
	}
	unordered_set<int> b1;
	for (int i = 0; i < 12; i++) {
		int rnd = rand() % 10;
		b1.insert(rnd);
	}
	print(a1);
	cout << endl;
	print(b1);
	cout << endl;
	print(a1 * b1);
}