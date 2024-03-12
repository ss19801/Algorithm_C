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
		arr[k - 1]++; //�� �� ��ҿ� 1�� ����
		for (int i = k - 1; arr[i] == n; i--) { //arr[i]�� n�� ������ for�� ���ư�.
			if (i == 0) { //
				return;
			}
			arr[i - 1]++; //���ڸ� ++
			arr[i] = 0; //�ø� ����
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