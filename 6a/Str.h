#pragma once
#include"_str.h"

class Str {
	_str* m_pStr;
public:
	Str() { m_pStr = new _str; }		//���� �� �����, �� �������
	Str(const char* p) {		// ����� ������
		m_pStr = new _str(p);
	}
	~Str() {
		m_pStr->Release(); 	// �� ���������� ������!
	}				// ��������� ������� ������!

	Str(const Str& s)
	{
		m_pStr = s.m_pStr; 	// ��������� �� ��� �� ������
		m_pStr->AddRef(); 	// ��������, ��� ���������
	}

	Str operator = (const Str& s) {
		if (this != &s) {
			s.m_pStr->AddRef(); // ����� �������?!
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}

	Str& operator += (const Str& s) {
		int length = len() + s.len();
		if (s.len() != 0) {		// ���������� ������ �� �������!
			_str* pstrTmp = new _str; 	// ����� ������
			delete[] pstrTmp->m_pszData;

			pstrTmp->m_pszData = new char[length + 1];
			strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
			strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);

			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}

	int replace(char ch_old, char ch_new) {
		int rep_count = 0;
		int s_len = len();
		if (s_len == 0) {
			return rep_count;
		}
		if (ch_old == ch_new) {
			return rep_count;
		}
		for (int i = 0; i < s_len; i++) {
			if (m_pStr->m_pszData[i] == ch_old) {
				m_pStr->m_pszData[i] = ch_new;
				rep_count++;
			}
		}
		return rep_count;
	}

	operator const char* () { return m_pStr->m_pszData; }
	int len() const {
		return strlen(m_pStr->m_pszData);
	}
};
