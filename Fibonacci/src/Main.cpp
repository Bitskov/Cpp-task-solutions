#include "Fibonacci.h"
#include "Matrix.h"

#include <iostream>
#include <fstream>

#include <chrono>
#include <cassert>
using namespace std;

number getNumberCl(int n);
extern Matrix Q;

int main() {
	ofstream out("fast_pow.dat");

	number prev = 0;
	number cur = 0;

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0;; i++) {
		prev = cur;
		cur = getNumber(i);
		if (cur >= prev) {
			cout << i << ' ' << cur << endl;
			auto finish = std::chrono::high_resolution_clock::now();
			auto delta = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
			out << i << ' ' << delta << endl;
		} else {
			break;
		}
	}
	return 0;
}

number getNumberCl(int n) {
	assert(n >= 0);
	if (n == 0) {
		return 0;
	}

	number pr = 0;
	number cur = 1;
	int i = n - 1;
	while (i > 0){
		cur = pr + cur;
		pr = cur - pr;
		i -= 1;
	}
	return cur;
}
