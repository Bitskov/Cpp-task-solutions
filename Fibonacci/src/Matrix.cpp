#include "Matrix.h"

#include <cassert>
#include <iostream>

typedef unsigned long long number;

Matrix::Matrix() {
	this->n = 0;
	this->m = 0;
	this->a = 0;
}

Matrix::Matrix(int n, int m) {
	this->n = n;
	this->m = m;
	this->a = new number[n*m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i*n+j] = 0;
		}
	}
}

Matrix::Matrix(number * a, int n, int m) {
	this->n = n;
	this->m = m;
	this->a = new number[n*m];
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->m; j++) {
			this->a[i*this->m+j] = a[i*this->m+j];
		}
	}
}

Matrix::Matrix(const Matrix & matrix) {
	this->n = matrix.n;
	this->m = matrix.m;
	this->a = new number[matrix.n*matrix.m];
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->m; j++) {
			this->a[i*this->m+j] = matrix.a[i*this->m+j];
		}
	}
}

Matrix::~Matrix() {
	if (this->a)
		delete[] this->a;
}

void Matrix::print() const {
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->m; j++) {
			std::cout << this->a[i*this->m+j] << ' ';
		}
		std::cout << std::endl;
	}
}

number Matrix::get(int i, int j) {
	return this->a[i*this->m + j];
}

Matrix Matrix::dot(const Matrix & other) {
	assert(this->m == other.n);

	int new_n = this->n;
	int new_m = other.m;

	number * a = new number[new_n * new_m];

	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < other.n; j++) {
			number sum = 0;
			for (int r = 0; r < this->m; r++) {
				sum += this->a[i*this->m + r] * other.a[r*other.m + j];
			}
			a[i*new_m + j] = sum;
		}
	}
	Matrix * result = new Matrix(a, new_n, new_m);
	return *result;
}

Matrix Matrix::pow(int n) {
	if (n == 1) {
		Matrix result = *this;
		return result;
	}

	if (n % 2 == 1) {
		Matrix m1 = *this;
		Matrix m2 = this->pow(n - 1);
		Matrix result = m1.dot(m2);
		//delete &m1;
		//delete &m2;
		return result;
	}
	else {
		Matrix m1 = this->dot(*this);
		Matrix result = m1.pow(n / 2);
		//delete &m1;
		return result;
	}
}

