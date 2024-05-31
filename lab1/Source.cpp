#include "polinom.h"
#include <string>
int main(){
	polinom p1, p2, p3;
	string s;
	p1.to_pol("3+3x^2z^3-7xyz^2");
	p2.to_pol("5z^3y^2x-3x^4y^2-5x^2z^3");
	p3.sub_pol(p1, p2);
	s = p3.print();
	cout << s;

}