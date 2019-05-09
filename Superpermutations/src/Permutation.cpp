#include "Permutation.h"
#include <vector>
#include <cassert>

Permutation::Permutation() {
	this->len = 0;
	this->p = new char[0];
}

Permutation::Permutation(char * p, int len) {
	this->len = len;
	this->p = new char[len];
	for (int i = 0; i < len; i++) {
		this->p[i] = p[i];
	}
}

Permutation::Permutation(const Permutation & p) {
	this->len = p.len;
	this->p = new char[this->len];
	for (int i = 0; i < this->len; i++) {
		this->p[i] = p.p[i];
	}
}

bool Permutation::contains(char c) {
	for (int i = 0; i < this->len; i++) {
		if (this->p[i] == c)
			return true;
	}
	return false;
}

void Permutation::append(char c) {
	this->len += 1;
	char * new_p = new char[len + 1];
	for (int i = 0; i < this->len - 1; i++) {
		new_p[i] = this->p[i];
	}
	new_p[this->len - 1] = c;
	delete this->p;
	this->p = new_p;
}

std::ostream& operator<< (std::ostream& os, Permutation const& p) {
	for (int i = 0; i < p.len; i++) {
		os << p.p[i];
	}
	return os;
}

std::vector<Permutation> Permutations(int n, int len) {
	if (len == 0) {
		std::vector<Permutation> vec(1);
		return vec;
	} else {
		std::vector<Permutation> smallerPermutations = Permutations(n, len - 1);
		std::vector<Permutation> newPermutations(0);
		for (Permutation & p : smallerPermutations) {
			for (char c='a'; c < 'a' + n; c++) {
				if (!p.contains(c)) {
					Permutation np = p;
					np.append(c);
					newPermutations.push_back(np);
				}
			}
		}
		return newPermutations;
	}
}
