#include <iostream>
#include "Bignum.h"
using namespace std;

void print(const Bignum & b);

int main() {
	Bignum a(999);
	print(a);
	Bignum b(999);
	print(b);
	cout << "aaa" << endl;
	cout << (a != b);
	return 0;
}

void print(const Bignum & b) {
	if (b.negative)
		cout << '-';
	for (unsigned int i = 0; i < b.length; i++) {
		cout << (int)(b.number[i]) << ' ';
	}
	cout << endl;
}
