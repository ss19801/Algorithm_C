#include <iostream>
#define MAXN 200
using namespace std;

long long fibo1(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else return fibo1(n - 1) + fibo1(n - 2);
}

long long fibo2(int n) {
	static long long memo[MAXN];
	if (memo[n] > 0) {
		return memo[n];
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	return memo[n] = fibo2(n - 1) + fibo2(n - 2);
}

long long fibo3(int n) {
	long long i, f_i, f_i_l, t;
	if (n == 1 || n == 2) {
		return 1;
	}
	f_i_l = 1;
	f_i = 1;
	for (i = 3; i <= n; i++) {
		t = f_i;
		f_i = f_i_l + f_i;
		f_i_l = t;
	}
	return f_i;
}

int main() {
	int n;
	cout << "input n: ";
	cin >> n;
	cout << fibo1(n) << endl << fibo2(n) << endl << fibo3(n);
	return 0;
}