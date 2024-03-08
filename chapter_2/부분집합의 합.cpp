#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int subset_sum(int s[], int n, int m) {
	if (n == 0) {
		if (m == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	return max(subset_sum(s, n - 1, m - s[n - 1]), subset_sum(s, n - 1, m));
}

int c[200][200];

void calculate_subset_sum(int s[], int n, int m) {
	for (int i = 0; i <= n; i++) {
		c[i][0] = 1;
	}
	for (int j = 1; j <= m; j++) {
		c[0][j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			c[i][j] = 0;
			if (j >= s[i - 1]) {
				if (c[i - 1][j - s[i - 1]] == 1) {
					c[i][j] = 1;
				}
			}
			if (c[i - 1][j] == 1) {
				c[i][j] = 1;
			}
		}
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	int* num = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	if (subset_sum(num, n, m) == 1) {
		cout << "Possible." << endl;
	}
	else {
		cout << "Impossible." << endl;
	}
	calculate_subset_sum(num, n, m);
	cout << c[n][m];
}

