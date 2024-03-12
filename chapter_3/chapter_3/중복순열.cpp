#include <iostream>
using namespace std;

void print_arr(int arr[], int arr_len) {
	for (int i = 0; i < arr_len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void rperm(int arr[], int len, int n, int k) {
	if (len == k) {
		print_arr(arr, len);
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[len] = i;
		rperm(arr, len + 1, n, k);
	}
}

void rperm2(int arr[], int n, int k) {
	for (int i = 0; i < k; i++) {
		arr[i] = 0;
	}
	while (1) {
		print_arr(arr, k);
		arr[k - 1]++; //맨 끝 요소에 1을 더함
		for (int i = k - 1; arr[i] == n; i--) { //arr[i]가 n이 같으면 for문 돌아감.
			if (i == 0) { //
				return;
			}
			arr[i - 1]++; //앞자리 ++
			arr[i] = 0; //올림 실행
		}
	}
}

int main() {
	int arr[100], n, k;
	cout << "input n, k: ";
	cin >> n >> k;
	rperm(arr, 0, n, k);
	rperm2(arr, n, k);
	return 0;
}