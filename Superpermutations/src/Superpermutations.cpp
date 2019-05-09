//============================================================================
// Name        : Superpermutations.cpp
// Author      : Alexei
//============================================================================

#include <iostream>
#include <vector>
#include "Permutation.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<Permutation> permutations = Permutations(n, n);
	for (const Permutation & p: permutations) {
		cout << p << endl;
	}
	return 0;
}

vector<char *> formSuperpositions(int n int & len);
