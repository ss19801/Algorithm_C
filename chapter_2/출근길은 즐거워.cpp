#include <iostream>
using namespace std;
#define M 100
#define N 100

int map[M][N];
int from[M][N]; // 어디서 왔는지 알려주는 배열
enum {LEFT,UP}; 

int max(int a, int b) {
	return a > b ? a : b;
}

int max_joy(int m, int n) {
	if (m == 0 && n == 0) {
		return map[0][0];
	}
	if (m == 0) {
		return max_joy(m, n - 1) + map[m][n];
	}
	if (n == 0) {
		return max_joy(m - 1, n) + map[m][n];
	}
	return max(max_joy(m - 1, n), max_joy(m, n - 1)) + map[m][n];
}

int joy[M][N];

void calculate_joy(int m, int n) {
	joy[0][0] = map[0][0];
	for (int i = 1; i < m; i++) {
		joy[i][0] = joy[i - 1][0] + map[i][0];
		from[i][0] = LEFT;
	}
	for (int j = 1; j < n; j++) {
		joy[0][j] = joy[0][j - 1] + map[0][j];
		from[0][j] = UP;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < m; j++) {
			if (joy[i - 1][j] > joy[i][j - 1]) {
				from[i][j] = LEFT;
			}
			else {
				from[i][j] = UP;
			}
			joy[i][j] = max(joy[i - 1][j], joy[i][j - 1]) + map[i][j];
		}
	}
}

void print_path(int m, int n) {
	if (m == 0 && n == 0) {
		return;
	}
	if (from[m][n] == LEFT) {
		print_path(m - 1, n);
	}
	else {
		print_path(m, n - 1);
	}
	cout << "(" << m << "," << n << ") ";
}

int main() {
	int m, n;
	cout << "input m,n: ";
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	cout << max_joy(m - 1, n - 1) << endl;
	calculate_joy(m, n);
	print_path(m - 1, n - 1);
	return 0;
}


/*
1 2 2 1 5
1 4 4 3 1
2 1 1 1 2
1 3 5 1 1
1 5 1 2 2
*/