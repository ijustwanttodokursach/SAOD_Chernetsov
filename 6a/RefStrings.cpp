#include <iostream>
#include"Str.h"
using namespace std;

int main()
{
    Str S = "aaabgaggagggg";
    S += "45";
    cout << S;
    cout << endl;
    int cnt = S.replace('a', 'c');
    cout << S<<" "<<cnt;
}