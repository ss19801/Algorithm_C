#include <iostream>
using namespace std;

#define MAXN 100
#define L 0
#define R 1

void print(int arr[], int arr_size) {
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] == L) {
			cout << "(";
		}
		else if (arr[i] == R) {
			cout << ")";
		}
	}
	cout << endl;
}

void paren(int to_open, int to_close, int arr[], int arr_size) {
	if (to_open == 0 && to_close == 0) {
		print(arr, arr_size);
		return;
	}
	if (to_open > 0) {
		arr[arr_size] = L;
		paren(to_open - 1, to_close+1, arr, arr_size + 1);
	}
	if (to_close > 0) {
		arr[arr_size] = R;
		paren(to_open, to_close-1, arr, arr_size + 1);
	}
}

int main() {
	int arr[MAXN], n;
	cin >> n;
	paren(n, 0, arr, 0);
	return 0;
}