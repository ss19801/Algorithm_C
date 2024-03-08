#include <iostream>
using namespace std;
#define M 100
#define N 100

int map[M][N] = { 0 };

long long num_path(int m, int n) {
	if (map[m][n] == 0) {
		return 0; //장애물
	}
	if (m == 0 && n == 0) {
		return 1; //시작점
	}
	return ((m > 0) ? num_path(m - 1, n) : 0) + ((n > 0) ? num_path(m, n - 1) : 0);
	//m>0,n=0 -> path(m-1,n) 호출
	//m=0,n>0 -> path(m,n-1) 호출
	//m>0,n>0 -> path(m-1,n)+path(m,n-1) 호출
}

long long path[M][N];

void calculate_path(int m, int n) {
	path[0][0] = map[0][0];
	for (int i = 1; i < m; i++) {
		if (map[i][0] == 0) {
			path[i][0] = 0;
		}
		else {
			path[i][0] = path[i - 1][0];
		}
	}
	for (int j = 1; j < n; j++) {
		if (map[0][j] == 0) {
			path[0][j] = 0;
		}
		else {
			path[0][j] = path[0][j - 1];
		}
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j] == 0) {
				path[i][j] = 0;
			}
			else {
				path[i][j] = path[i - 1][j] + path[i][j - 1];
			}
		}
	}
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
	cout << num_path(m - 1, n - 1) << endl;
	calculate_path(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}