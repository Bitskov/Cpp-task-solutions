#include "Matrix.h"

#include <iostream>
using namespace std;

int main() {
	int a[] = {1, 2, 3, 4, 5, 6};

	Matrix m1(&a[0], 2, 3);
	Matrix m2(&a[0], 3, 2);

	//m1.print();
	//m2.print();

	Matrix r = m1.dot(m2);

	r.print();

	return 0;
}
