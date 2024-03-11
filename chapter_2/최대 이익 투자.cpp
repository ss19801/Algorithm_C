//Resource Allocation Problem
#include <iostream>
using namespace std;

#define MAXM 100
#define MAXN 100

int r[MAXN][MAXM];
int max_return[MAXN][MAXM];



void calculate_return(int n, int m) {
	int max, t, loc = 0;
	for (int i = 0; i <= m; i++) {
		max_return[0][i] = r[0][i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			max = -1;
			for (int k = 0; k <= j; k++) {
				t = max_return[i - 1][k] + r[i][j - k];
				if (t > max) {
					max = t;
					loc = k;
				}
			}
			max_return[i][j] = max;
		}
	}
}


int main() {
	int m, n;
	cout << "input m,n: ";
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		r[i][0] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> r[j][i];
		}
	}
	calculate_return(n - 1, m);
	cout << max_return[n - 1][m];
	return 0;

}

/*
4 3
2 3 1 
4 5 3
6 6 7
9 8 9
*/