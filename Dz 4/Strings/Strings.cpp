#include <iostream>
#include "Str.h"

using namespace std;

void Test(Str s){}

int main()
{
    Str s("123");
    cout << s;

    int lenn = strlen(s);

    Test(s);

    cout << s<< endl;

    Str t;
    t = s;
    t = s = t;

    cout << t << " " << s<<endl;

    s += "123";
    cout << s;
   
}
