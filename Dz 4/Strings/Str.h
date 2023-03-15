#pragma once
class Str
{
	char* m_pszText;
public:

	Str(){
		m_pszText = new char[1]{ 0 };
	}

	Str(const char *p){
		if (p) {
			m_pszText = new char[strlen(p) + 1];
			strcpy_s(m_pszText, strlen(p) + 1, p);
		}
		else
			m_pszText = new char[1]{ 0 };
	}

	Str(const Str& s){
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText, strlen(s.m_pszText) + 1, s.m_pszText);
	}


	~Str() { delete [] m_pszText; }

	operator const char* ()const { return m_pszText; }

	 const Str& operator = (const Str& s){
		if (&s == this) {
			return *this;
		}
		delete[] m_pszText;

		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText, strlen(s.m_pszText) + 1, s.m_pszText);
		return *this;
	}

	 Str& operator +=(const char* sz) {
		 char* cur = new char[strlen(m_pszText) + strlen(sz) + 1];
		 for (size_t i = 0; i < strlen(m_pszText); i++) {
			 cur[i] = m_pszText[i];
		 }
		 int z = 0;
		 for (size_t i = strlen(m_pszText); i < strlen(m_pszText) + strlen(sz) + 1; i++) {
			 cur[i] = sz[z];
			 z++;
		 }
		 delete[] m_pszText;
		 m_pszText = new char[strlen(cur)+1];
		 strcpy_s(m_pszText, strlen(cur) + 1, cur);
		 delete [] cur;
		 return *this;
	 }
};
