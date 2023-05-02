#include <iostream>
#include<memory>
#include"Test.h"
using namespace std;

weak_ptr<Test> wp;

int main()
{
    {
        auto sp = shared_ptr<Test>(new Test);
        cout << sp.use_count()<<endl;
        wp = sp;
        cout << wp.use_count() << endl;
        auto p = wp.lock();
        if (p) {
            cout << "object is alive " <<p.use_count()<< endl;
        }
        else {
            cout << "no owing object" << endl;
        }
    }
    auto p = wp.lock();
    if (p) {
        cout << "object is alive " << p.use_count() << endl;
    }
    else {
        cout << "no owing object" << endl;
    }
}