#pragma once
#include <cmath>
using namespace std;

class complex {
public:
	double Re, Im;

	complex(double re= 0, double im = 0) {
		Re = re;
		Im = im;
	}
	
	complex operator +(const complex& c)const{
		return complex(Re + c.Re, Im + c.Im);
	}
	complex operator -(const complex& c)const{
		return complex(Re - c.Re, Im - c.Im);
	}
	complex operator *(const complex& c)const{
		return complex(Re * c.Re-Im*c.Im, Re*c.Im+c.Re*Im);
	}
	complex operator /(const complex& c) const{
		return complex((Re * c.Re + Im * c.Im) / (c.Re * c.Re + c.Im * c.Im), (-Re * c.Im + c.Re * Im) / (c.Re * c.Re + c.Im * c.Im));
	}
	
	inline complex conjugate() {
		return complex(Re, -Im);
	}

	inline double mod() {
		return sqrt(pow(Re,2) + pow(Im,2));
	}

	inline double arg() {
		if (mod() == 0) {
			return 0;
		}
		if (Re > 0) {
			return atan(Im / Re);
		}
		if (Re < 0) {
			if (Im >= 0) {
				return acos(-1) + atan(Im / Re);
			}
			else {
					return -acos(-1) - atan(Im / Re);
				}
			}
		else {
			if (Im > 0) {
				return acos(0);
			}
			if (Im < 0) {
				return -acos(0);
			}
		}
	}

};
inline ostream& operator << (ostream& o, const complex& c) {
	return o << '(' << c.Re << ", " << c.Im << ')';
}



