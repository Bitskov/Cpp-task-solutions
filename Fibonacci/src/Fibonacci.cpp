#include <cassert>

#include "Fibonacci.h"
#include "Matrix.h"

number q[] = {1, 1, 1, 0};

Matrix Q(&q[0], 2, 2);

number getNumber(int n) {
	assert(n >= 0);

	if (n > 2) {
		Matrix nq = Q.pow(n - 1);
		return nq.get(0, 0);
	}
	else {
		return n != 0;
	}
	return 0;
}
