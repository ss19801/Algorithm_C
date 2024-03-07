#include <iostream>
#define MAXN 20
using namespace std;

void print_code(int code[], int len) {
	int i;
	for (i = 0; i < len; i++) {
		cout << code[i] << " ";
	}
	cout << endl;
}

void print_gray(int code[], int n, int index,int reverse) {
	if (index == n) {
		print_code(code, n);
		return;
	}
	code[index] = reverse;
	print_gray(code, n, index + 1, 0);
	code[index] = 1 - reverse;
	print_gray(code, n, index + 1, 1);
}

int main() {
	int code[MAXN] = { 0 };
	int n;
	cin >> n;
	print_gray(code, n, 0, 0);
	return 0;
}