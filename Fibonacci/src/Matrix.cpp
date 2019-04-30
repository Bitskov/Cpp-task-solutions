#include "Matrix.h"

#include <cassert>
#include <iostream>

Matrix::Matrix() {
	this->n = 0;
	this->m = 0;
	this->a = 0;
}

Matrix::Matrix(int n, int m) {
	this->n = n;
	this->m = m;
	this->a = new int[n*m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i*n+j] = 0;
		}
	}
}

Matrix::Matrix(int * a, int n, int m) {
	this->n = n;
	this->m = m;
	this->a = new int[n*m];
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->m; j++) {
			this->a[i*this->m+j] = a[i*this->m+j];
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

Matrix Matrix::dot(const Matrix & other) {
	assert(this->m == other.n);

	int new_n = this->n;
	int new_m = other.m;

	int * a = new int[new_n * new_m];

	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < other.n; j++) {
			int sum = 0;
			for (int r = 0; r < this->m; r++) {
				sum += this->a[i*this->m + r] * other.a[r*other.m + j];
			}
			a[i*new_m + j] = sum;
		}
	}
	Matrix * result = new Matrix(a, new_n, new_m);
	return *result;
}

