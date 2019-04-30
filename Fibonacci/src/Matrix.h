#ifndef MATRIX_H_
#define MATRIX_H_

struct Matrix {
	Matrix();
	Matrix(int n, int m);
	Matrix(int * a, int n, int m);
	virtual ~Matrix();

	void print() const;

	Matrix dot(const Matrix & other);

private:
	int n,m;
	int * a;
};

#endif /* MATRIX_H_ */
