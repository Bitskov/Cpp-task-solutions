#ifndef BIGNUM_H_
#define BIGNUM_H_

#include <iostream>

struct Bignum {
	Bignum();
	Bignum(int a, bool negative=false);
	Bignum(unsigned char * number, unsigned int length, bool negative=false);

	virtual ~Bignum();

	unsigned char * number;
	unsigned int length;
	bool negative = false;

	Bignum operator+(const Bignum & b);
	Bignum operator-(const Bignum & b);

	bool operator>(const Bignum & b);
	bool operator<(const Bignum & b);
	bool operator==(const Bignum & b);
	bool operator!=(const Bignum & b);
	bool operator<=(const Bignum & b);
	bool operator>=(const Bignum & b);

};

#endif /* BIGNUM_H_ */
