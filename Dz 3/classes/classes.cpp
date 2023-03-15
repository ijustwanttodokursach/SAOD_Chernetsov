#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    complex c(4,5);
    complex d(8, 9);
    cout << c/d<< endl;

    complex v[3]{ 1,2,complex(2,3) };
    for (int i = 0; i < 3; i++) {
        cout << v[i];
    }
    cout << endl;

    complex* pc;
    pc = new complex(1);
    cout << *pc<< " re = "<< pc->Re<<" im = "<<pc->Im << endl;
    delete pc;
    pc = new complex;
    cout << *pc << " re = " << pc->Re << " im = " << pc->Im << endl;
    delete pc;
    pc = new complex(1,2);
    cout << *pc << " re = " << pc->Re << " im = " << pc->Im << endl;
    delete pc;
    pc = new complex[3];
    pc[1] = complex(1, 100);
    cout << pc[1].Re;
    delete pc;
}