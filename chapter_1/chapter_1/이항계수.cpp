#include <iostream>
#define MAXN 200
using namespace std;

long long choose(int n, int r) {
	if (r == 0 || n == r)
		return 1;
	return choose(n - 1, r - 1) + choose(n - 1, r);
}
 
//메모이제이션 기법 이용
long long choose2(int n, int r) {
	static long long memo[MAXN][MAXN];
	if (memo[n][r] > 0) {
		return memo[n][r];
	}
	if (r == 0 || n == r) {
		return 1;
	}
	return memo[n][r] = choose2(n - 1, r - 1) + choose2(n - 1, r);
}

int main() {
	int n, r;
	cout << "input n, r : ";
	cin >> n >> r;
	cout << choose(n, r) << endl;
	cout << choose2(n, r);
	return 0;
}