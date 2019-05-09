#ifndef PERMUTATION_H_
#define PERMUTATION_H_
#include <iostream>
#include <vector>

class Permutation {
public:
	Permutation();
	Permutation(char * p, int len);
	Permutation(const Permutation & p);

	bool contains(char c);
	void append(char c);

	char * p;
	int len;
};

std::ostream & operator<<(std::ostream & os, Permutation const & p);

std::vector<Permutation> Permutations(int n, int len);

int permutationsNumber(int n, int len);

#endif /* PERMUTATION_H_ */
