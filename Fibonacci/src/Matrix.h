#ifndef MATRIX_H_
#define MATRIX_H_

typedef unsigned long long number;

struct Matrix {
	Matrix();
	Matrix(int n, int m);
	Matrix(number * a, int n, int m);
	Matrix(const Matrix & matrix);

	virtual ~Matrix();

	number get(int i, int j);
	void print() const;

	Matrix dot(const Matrix & other);
	Matrix pow(int n);

private:
	int n,m;
	number * a;
};

#endif /* MATRIX_H_ */
