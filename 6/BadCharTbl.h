#pragma once
#include<list>
using namespace std;
class BadCharTbl {
	int badChar[256];
public:
	BadCharTbl() {}

	int operator[](unsigned char c) const {
		return badChar[c];
	}

	list<int> BMH(const char* t, const char* T) {
		// 0123456789
		// abc abc abc
		// abc
		// 048
		Init(t);
		list<int> result;
		int shift;
		int len_T = strlen(T);
		int len_t = strlen(t);
		int cp = 0;
		while (cp<len_T) {
			for (int j = len_t - 1; j >= 0; j--) {
				if (t[j] != T[cp+j]) {
					shift = std::max(j - badChar[T[cp+len_t]],1);
					cp += shift;
					break;
				}
				if (j == 0) {
					result.push_back(cp);
					shift = (cp + len_t < len_T) ? len_t - badChar[T[cp + len_t]] : 1;
					cp += shift;
				}
			}
		}
		// aaaaaaaa
		// aa
		//
		return result;
	}
private:
	void Init(const char* s) {
		int len = strlen(s);
		for (int i = 0; i < 256; i++) {
			badChar[i] = len - 1;
		}
		for (int i = 0; i < len - 1; i++) {
			badChar[s[i]] = i;
		}
	}
};