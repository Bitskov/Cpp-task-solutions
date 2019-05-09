#include <string>
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

void notCipher(const char *, const char *);
void xorCipher(const char * in_file, const char * out_file, char * key);
void xorCoolEncoder(char * in_file, char * out_file, char * key);
char * generateKey();
void print(char * a, int len, ofstream & out);

int main() {
	/*notCipher("War and Peace.txt", "War and Peace-not.txt");
	notCipher("War and Peace-not.txt", "War and Peace-not-dec.txt");

	char * key = generateKey();
	xorCipher("War and Peace.txt", "War and Peace-xor.txt", key);
	xorCipher("War and Peace-xor.txt", "War and Peace-xor-dec.txt", key);*/
	char * key = generateKey();
	//xorCoolEncoder("War and Peace.txt", "War and Peace-xor.txt", key);
	ifstream in("War and Peace.txt");
	do {
		char ch = in.get();
		cout << ch << " ";
		for (int i = 0; i < 8; i++) {
			cout << (bool)((ch << i) & (1 << i));
		}
		cout << endl;
	} while(!in.eof());
	return 0;
}

void notCipher(const char * in_file, const char * out_file) {
	ifstream in(in_file, ios::binary | ios::in);
	ofstream out(out_file, ios::binary | ios::out);

	do {
		char ch = in.get();
		ch = ~ch;
		out << ch;
	} while(!in.eof());
}

void xorCipher(const char * in_file, const char * out_file, char * key) {
	ifstream in(in_file, ios::binary | ios::in);
	ofstream out(out_file, ios::binary | ios::out);

	int j = 0;
	do {
		char ch = in.get();
		ch = key[j]^ch;
		out << ch;

		j = (j+1) % 5;
	} while(!in.eof());
}

char * generateKey() {
	char * key = new char[6];
	for (int i = 0; i < 5; i++) {
		key[i] = rand() % 26 + 'a';
	}
	key[5] = 0;
	return key;
}

void xorCoolEncoder(char * in_file, char * out_file, char * key) {
	ifstream in(in_file);
	ofstream out(out_file);

	int i = 0;
	char chars[7];
	do {
		chars[7] = in.get();
		i++;

		if (i == 8) {
			char ch = in.get();
			for (int j = 0; j < 7; j++) {
				chars[i] ^= ((ch << (j + 1)) & (1 << 8));
				out << chars[i];
			}
		}
	} while (!in.eof());
}

void print(char * a, int len, ofstream & out) {
	for (int i = 0; i < len; i++) {
		out << a[i];
	}
	out << endl;
}

