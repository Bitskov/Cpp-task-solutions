#include "Fibonacci.h"
#include "Matrix.h"

#include <iostream>
#include <fstream>

#include <ctime>
#include <cassert>
#include <climits>
using namespace std;

number getNumberCl(int n);
int fastPowIterations(int n);
extern Matrix Q;

int main() {
	cout << getNumber(20) << endl;
	return 0;
}

number getNumberCl(int n) {
	assert(n >= 0);
	if (n == 0) {
		return 0;
	}

	number pr = 0;
	number cur = 1;

	// Iteration counter
	int a = 0;
	// Delete

	int i = n - 1;
	while (i > 0){
		cur = pr + cur;
		pr = cur - pr;
		i -= 1;
		a++;
	}
	return a;
}

int fastPowIterations(int n) {
	if (n == 1) {
		return 0;
	}

	if (n % 2 == 1) {
		return fastPowIterations(n - 1) + 1;
	} else {
		return fastPowIterations(n / 2) + 1;
	}
}
