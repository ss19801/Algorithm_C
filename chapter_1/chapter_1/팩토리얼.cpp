#include <iostream>
using namespace std;

int factorial(int n) {
	int r = 1;
	for (int i = 2; i <= n; i++) {
		r *= i;
	}
	return r;
}

int factorial2(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n * factorial2(n - 1);
	}
}

int main() {
	return 0;
}