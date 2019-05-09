#include "Bignum.h"
#include <algorithm>

int P = 10;

Bignum::Bignum() {
	this->length = 0;
	this->number = new unsigned char[1];
	this->number[0] = 0;
}

Bignum::Bignum(int a, bool negative) {
	this->negative = negative;
	int p = 0;
	int max = 1;
	if (a == 0) {
			p = 1;
	} else {
		while (max - 1 < a) {
			max *= P;
			p += 1;
		}
	}
	this->length = p;
	this->number = new unsigned char[this->length];
	for (unsigned int i = 0; i < this->length; i++) {
		this->number[i] = a % P;
		a /= P;
	}
}

Bignum::Bignum(unsigned char * a, unsigned int length, bool negative) {
	this->negative = negative;
	this->length = length;
	this->number = a;
}

Bignum::~Bignum() {
	delete[] this->number;
}

bool Bignum::operator<(const Bignum & b) {
	unsigned int max_len = std::max(b.length, this->length);
	for (unsigned int i = max_len - 1; i >= 0; i--) {
		unsigned char a1 = (i < this->length) ? this->number[i] : 0;
		unsigned char a2 = (i < b.length) ? b.number[i] : 0;
		if (a1 < a2)
			return true;
	}
	return false;
}

bool Bignum::operator>(const Bignum & b) {
	unsigned int max_len = std::max(b.length, this->length);
	for (unsigned int i = max_len - 1; i >= 0; i--) {
		unsigned char a1 = (i < this->length) ? this->number[i] : 0;
		unsigned char a2 = (i < b.length) ? b.number[i] : 0;
		if (a1 > a2)
			return true;
	}
	return false;
}

bool Bignum::operator==(const Bignum & b) {
	unsigned int max_len = std::max(b.length, this->length);
	for (unsigned int i = max_len - 1; i >= 0; i--) {
		unsigned char a1 = (i < this->length) ? this->number[i] : 0;
		unsigned char a2 = (i < b.length) ? b.number[i] : 0;
		if (a1 != a2)
			return false;
	}
	return false;
}

bool Bignum::operator!=(const Bignum & b) {
	return !(*this == b);
}

bool Bignum::operator<=(const Bignum & b) {
	return ((*this < b) | (*this==b));
}

bool Bignum::operator>=(const Bignum & b) {
	return ((*this > b) | (*this==b));
}


Bignum Bignum::operator+(const Bignum & b) {
	unsigned int new_len = std::max(b.length, this->length) + 1;
	unsigned char * new_number = new unsigned char[new_len];
	int rest = 0;
	for (unsigned int i = 0; i < new_len; i++) {
		unsigned char a1 = (i < this->length) ? this->number[i] : 0;
		unsigned char a2 = (i < b.length) ? b.number[i] : 0;
		new_number[i] = (a1 + a2 + rest) % P;
		rest = (a1 + a2 + rest) / P;
	}
	return Bignum(new_number, (new_number[new_len - 1] != 0) ? new_len : new_len - 1);
}

/*Bignum Bignum::operator+(const Bignum & b) {
	;
}*/

