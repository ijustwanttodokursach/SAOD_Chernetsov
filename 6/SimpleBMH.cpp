#include <iostream>
#include<string>
#include "BadCharTbl.h"
#include<chrono>
//#define _BM_

using namespace std;
int main()
{
    BadCharTbl B;
    int alphaBetSize = 'b' - 'a' + 1;
   /* for (int i = 0; i < N; i++) {
        s[i] = rand() % alphaBetSize + 'a';
    }
    for (int i = 0; i < M; i++) {
        s1[i] = rand() % alphaBetSize + 'a';
    }
    for (int i = 0; i < strlen(s1); i++) {
        cout << s1[i];
    }
    cout << endl;
    for (int i = 0; i < strlen(s); i++) {
        cout << s[i];
    }
    cout << endl;*/
    //auto start = chrono::steady_clock::now();
#ifdef _BM_
    int N, M = 6;
    char* s1 = new char[M + 1]{ 0 };
    for (int i = 0; i < M; i++)
        s1[i] = rand() % alphaBetSize + 'a';

    for (int N = 128; N <= pow(2, 13); N *= 4) {
        char* s = new char[N + 1]{ 0 };
        for (int i = 0; i < N; i++) {
            s[i] = rand() % alphaBetSize + 'a';
        }
        auto start = chrono::steady_clock::now();
        list<int> res = B.BMH(s1,s);
        auto stop = chrono::steady_clock::now();
        auto dt = chrono::duration_cast<chrono::microseconds>(stop - start).count();
        cout << dt << endl;
    }

#else
    int N, M = 6;
    char* s1 = new char[M + 1]{ 0 };
    for (int i = 0; i < M; i++)
        s1[i] = rand() % alphaBetSize + 'a';
    string t(s1);
    for (int N = 128; N <= pow(2, 13); N *= 4) {
        char* s = new char[N + 1]{ 0 };
        for (int i = 0; i < N; i++) {
            s[i] = rand() % alphaBetSize + 'a';
        }
        string Strng(s);
        auto start = chrono::steady_clock::now();
        Strng.find(t, 0);
        auto stop = chrono::steady_clock::now();
        auto dt = chrono::duration_cast<chrono::microseconds>(stop - start).count();
        cout << dt << endl;
    }
#endif
    //auto stop = chrono::steady_clock::now();
    //auto dt = chrono::duration_cast<chrono::microseconds>(stop - start).count();

}
