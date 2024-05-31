#include "gtest/gtest.h"
#include "polinom.h"

TEST(TectingOperation, add) {
	polinom p1, p2, p3;
	string s;
	p1.to_pol("3+3x^2z^3-7xyz^2");
	p2.to_pol("5z^3y^2x-3x^4y^2-5x^2z^3");
	p3.add_pol(p1, p2);
	s = p3.print();
	EXPECT_EQ("3-7xyz^2+5xy^2z^3-2x^2z^3-3x^4y^2", s);
}
TEST(TectingOperation, mult) {
	polinom p1, p2, p3;
	string s;
	p1.to_pol("3+3x^2z^3-7xyz^2");
	p2.to_pol("5z^3y^2x-3x^4y^2-5x^2z^3");
	p3.mult_pol(p1, p2);
	s = p3.print();
	EXPECT_EQ("15xy^2z^3-15x^2z^3-35x^2y^3z^5+35x^3yz^5+15x^3y^2z^6-15x^4z^6-9x^4y^2+21x^5y^3z^2-9x^6y^2z^3", s);
}
TEST(TectingOperation, mult_st9) {
	polinom p1, p2, p3;
	string s;
	p1.to_pol("3+3x^2z^3-7xyz^9");
	p2.to_pol("5z^3y^2x-3x^4y^2-5x^2z^3");
	p3.mult_pol(p1, p2);
	s = p3.print();
	EXPECT_EQ("0", s);
}
TEST(TectingOperation, mult_on_num) {
	polinom p1, p2;
	string s;
	p1.to_pol("3+3x^2z^3-7xyz^2");
	p2.mult_num(p1, 3);
	s = p2.print();
	EXPECT_EQ("9-21xyz^2+9x^2z^3", s);
}
TEST(TectingOperation, sub) {
	polinom p1, p2, p3;
	string s;
	p1.to_pol("3+3x^2z^3-7xyz^2");
	p2.to_pol("5z^3y^2x-3x^4y^2-5x^2z^3");
	p3.sub_pol(p1, p2);
	s = p3.print();
	EXPECT_EQ("3-7xyz^2-5xy^2z^3+8x^2z^3+3x^4y^2", s);
}

