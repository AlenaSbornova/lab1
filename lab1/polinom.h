#pragma once
#include <iostream>
using namespace std;
#include <string>
struct monom
{
	int ko; //для коэффицента перед мономом
	int st; //для степеней при xyz
	monom* next;
};
class polinom
{
private:
	monom* first;
	string res;
public:
	polinom() {
		first = new monom;
		first->ko = 0;
		first->st = -1;
		first->next = 0;
	}
	void clear() {
		while (first->next != 0) {
			this->delete_mon(first->next->st);
		}
	}
	void add_mon(int k, int s) {
		monom* mon;
		monom* mon1;
		mon = first;
		while (mon->next != 0) {
			if (mon->next->st < s) {
				mon = mon->next;
			}
			else
				break;
		}
		mon1= mon->next;
		mon->next = new monom;
		mon->next->ko = k;
		mon->next->st = s;
		mon->next->next = mon1;
	}
	void delete_mon(int s) {
		monom* mon;
		monom* mon1;
		mon = first;
		mon1 = first;
		while (mon->st!=s) {
			mon1 = mon;
			mon = mon->next;
		}
		mon1->next = mon->next;
		delete mon;
	}
	 string print(){
		 monom* mon;
		 int re;
		 int x, y, z;
		 mon = first;
		 if (mon->next != 0) {
			 mon = mon->next;
			 re = mon->ko;
			 res += to_string(re);
			 re = mon->st;
			 z = re % 10;
			 y = (re % 100) / 10;
			 x = re / 100;
			 if (x > 1) {
				 res += "x^";
				 res += to_string(x);
			 }
			 if (x == 1) {
				 res += "x";
			 }
			 if (y > 1) {
				 res += "y^";
				 res += to_string(y);
			 }
			 if (y == 1) {
				 res += "y";
			 }
			 if (z > 1) {
				 res += "z^";
				 res += to_string(z);
			 }
			 if (z == 1) {
				 res += "z";
			 }
		 }
		 else
			 res = "0";
		 while (mon->next!=0) {
			 mon = mon->next;
			 re = mon->ko;
			 if (re > 0) {
				 res += "+";
			 }
			 res += to_string(re);
			 re = mon->st;
			 z = re % 10;
			 y = (re % 100) / 10;
			 x = re / 100;
			 if (x > 1) {
				 res += "x^";
				 res += to_string(x);
			 }
			 if (x == 1) {
				 res += "x";
			 }
			 if (y > 1) {
				 res += "y^";
				 res += to_string(y);
			 }
			 if (y == 1) {
				 res += "y";
			 }
			 if (z > 1) {
				 res += "z^";
				 res += to_string(z);
			 }
			 if (z == 1) {
				 res += "z";
			 }
		 }
		 return res;
	}
	 void to_pol(string s) {
		 int n;
		 int k=1;
		 int stp=0;
		 int koe=1;
		 n = s.size();
		 for (int i = 0; i < n; i++) {
			 if ((i == 0) && (s[i] == '-'))
				 k = -1;
			 if ((i != 0) && (s[i] == '-')) {
				 this->add_mon(k*koe, stp);
				 k = -1;
				 koe = 1;
				 stp = 0;
			 }
			 if ((i != 0) && (s[i] == '+')) {
				 this->add_mon(k*koe, stp);
				 k = 1;
				 koe = 1;
				 stp = 0;
			 }
			 if ((s[i] >= '0') && (s[i] <= '9')) {
				 koe =  (s[i] - '0');
				 while ((s[i + 1] >= '0') && (s[i + 1] <= '9')) {
					 i++;
					 koe = koe * 10 + (s[i] - '0');
				 }
			 }
			 if ((s[i] == 'x') && s[i + 1] == '^') {
				 i += 2;
				 stp = stp + (s[i] - '0') * 100;
			 }
			 if ((s[i] == 'y') && s[i + 1] == '^') {
				 i += 2;
				 stp = stp + (s[i] - '0') * 10;
			 }
			 if ((s[i] == 'z') && s[i + 1] == '^') {
				 i += 2;
				 stp = stp + (s[i] - '0');
			 }
			 if ((s[i] == 'x') && s[i + 1] != '^') {
				 stp += 100;
			 }
			 if ((s[i] == 'y') && s[i + 1] != '^') {
				 stp += 10;
			 }
			 if ((s[i] == 'z') && s[i + 1] != '^') {
				 stp += 1;
			 }
		 }
		 this->add_mon(k * koe, stp);
	 }
	 polinom operator=(polinom p) {
		 this->clear();
		 monom* mon;
		 mon = p.first;
		 while (mon != 0) {
			 this->add_mon(mon->ko, mon->st);
			 mon = mon->next;
		 }
		 return *this;
	 }
	 polinom add_pol(polinom p1,polinom p2) {
		 monom* m1;
		 monom* m2;
		 m1 = p1.first->next;
		 m2 = p2.first->next;
		 while ((m1!= 0) || (m2 != 0)) {
			 if (m1 == 0) {
				 this->add_mon(m2->ko,m2->st);
				 m2 = m2->next;
			 }
			 if ((m2 == 0) && (m1!=0)) {
				 this->add_mon(m1->ko, m1->st);
				 m1 = m1->next;
			 }
			 if ((m1 != 0) && (m2 != 0)) {
				 if (m1->st > m2->st) {
					 this->add_mon(m2->ko, m2->st);
					 m2 = m2->next;
				 }
			 }
			 if ((m1 != 0) && (m2 != 0)) {
				 if (m1->st < m2->st) {
					 this->add_mon(m1->ko, m1->st);
					 m1 = m1->next;
				 }
			 }
			 if ((m1 != 0) && (m2 != 0)) {
				 if (m1->st == m2->st)  {
					 this->add_mon(m2->ko + m1->ko, m2->st);
					 m1 = m1->next;
					 m2 = m2->next;
				 }
			 }
		 }
		 return p2;
	 }
	 polinom mult_pol(polinom p1, polinom p2) {
		 monom* m1;
		 monom* m2;
		 int x1, x2, y1, y2, z1, z2,stp;
		 m1 = p1.first->next;
		 m2 = p2.first->next;
		 while (m1 != 0) {
			 z1 = m1->st % 10;
			 y1 = (m1->st % 100) / 10;
			 x1 = m1->st / 100;
			 m2 = p2.first->next;
			 while (m2 != 0) {
				 z2 = m2->st % 10;
				 y2 = (m2->st % 100) / 10;
				 x2 = m2->st / 100;
				 if ((x1 + x2 > 9) || (y1 + y2 > 9) || (z1 + z2 > 9)) {
					 cout << "error";
					 this->clear();
					 return *this;
				 }
				 else {
					 stp = (x1 + x2) * 100 + (y1 + y2) * 10 + z1 + z2;
					 this->add_mon(m1->ko * m2->ko, stp);
				 }
				 m2 = m2->next;
			 }
			 m1 = m1->next;
		 }
		 return *this;
	 }
	 polinom mult_num(polinom p, int n) {
		 monom* m1 = p.first->next;
		 while (m1 != 0) {
			 this->add_mon(n * m1->ko, m1->st);
			 m1 = m1->next;
		 }
		 return *this;
	 }
	 polinom sub_pol(polinom p1, polinom p2) {
		 monom* m1;
		 monom* m2;
		 m1 = p1.first->next;
		 m2 = p2.first->next;
		 while ((m1 != 0) || (m2 != 0)) {
			 if (m1 == 0) {
				 this->add_mon(-m2->ko, m2->st);
				 m2 = m2->next;
			 }
			 if ((m2 == 0) && (m1 != 0)) {
				 this->add_mon(m1->ko, m1->st);
				 m1 = m1->next;
			 }
			 if ((m1 != 0) && (m2 != 0)) {
				 if (m1->st > m2->st) {
					 this->add_mon(-m2->ko, m2->st);
					 m2 = m2->next;
				 }
			 }
			 if ((m1 != 0) && (m2 != 0)) {
				 if (m1->st < m2->st) {
					 this->add_mon(m1->ko, m1->st);
					 m1 = m1->next;
				 }
			 }
			 if ((m1 != 0) && (m2 != 0)) {
				 if (m1->st == m2->st) {
					 if (m1->ko != m2->ko) {
						 this->add_mon(m1->ko - m2->ko, m2->st);
					 }
					 m1 = m1->next;
					 m2 = m2->next;
				 }
			 }
		 }
		 return p2;
	 }
};

