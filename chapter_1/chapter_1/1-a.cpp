#include <iostream>
using namespace std;

int sum_exp1(int n, int k) {
	static int answer = 0;
	for (int i = 1; i <= n; i++) {
		int num = 1;
		for (int j = 1; j <= k; j++) {
			num *= i;
		}
		answer += num;
	}
	return answer;
}

int exp2(int n, int k) {
	if (k == 0) {
		return 1;
	}
	else if (k == 1) {
		return n;
	}
	else if (k % 2 == 0) {
		int half = exp2(n, k / 2);
		return half * half;
	}
	else {
		int half = exp2(n, (k - 1) / 2);
		return n * half * half;
	}
}

int sum_exp2(int n, int k) {
	if (n < 1) {
		return 0;
	}
	else {
		return exp2(n, k) + sum_exp2(n-1 , k);
	}
}

int main() {
	int answer = 0;
	int n, k;
	cout << "input n, k: ";
	cin >> n >> k;
	cout << sum_exp1(n, k) << endl;
	cout << sum_exp2(n, k);
}