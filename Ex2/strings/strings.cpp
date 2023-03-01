#include <iostream>
using namespace std;

int len(const char* s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        count = i;
    }
    return count+1;
}

int compare(const char* s, const char* t) {
    if (len(s) > len(t)) {
        return 1;
    }
    else if (len(s) < len(t)) {
        return -1;
    }
    else if (len(t) == len(s)) {
        return 0;
    }
}

int main()
{
    char str[] = "Hello";
    cout << str;
    cout << strlen(str) << ' ' << sizeof(str);
    char t[32];
    for (char *pd = t, *ps = str; *pd++ = *ps++;);
    cout << endl;
    cout << len("hellohello")<<endl;
    cout << compare("hell", "helllll");

}
