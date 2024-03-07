#include <iostream>
#define MAXN 50
using namespace std;
int result = 0;

void partition(int n, int m, int arr[], int arr_len) {
	if (n < m) {
		m = n;
	}
	if (n == 0) {
		for (int i = 0; i < arr_len; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		result++;
		return;
	}

	for (int i = m; i >=1; i--) {
		arr[arr_len] = i;
		partition(n - i, i, arr, arr_len + 1);
	}
}

int partition_memo(int n, int m) {
	static int memo[MAXN][MAXN];
	int count = 0;
	if (n < m) {
		m = n;
	}
	if (memo[n][m] > 0) {
		return memo[n][m];
	}
	if (n == 0) {
		return memo[n][m] = 1;
	}
	for (int i = 1; i <= m; i++) {
		count += partition_memo(n - i, i);
	}
	return memo[n][m] = count;

}

int partition2(int n,int arr[],int arr_len,int prev) {
	int count = 0;
	if (n == 0) {
		for (int i = 0; i < arr_len; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return 0;
	}
	for (int i = 1; i <= n - 1; i++) {
		arr[arr_len] = i;
		count += partition2(n - i,arr,arr_len+1,i);
	}
	return count + 1;
}

void print_partition(int arr[], int arr_len) {
	cout << "Partition: ";
	for (int i = 0; i < arr_len; ++i) {
		cout << arr[i];
		if (i < arr_len - 1) {
			cout << " + ";
		}
	}
	cout << endl;
}

int partition2(int n) {
	int count = 0;
	for (int i = 1; i <= n - 1; i++) {
		count += partition2(n - i);
	}
	return count + 1;
}


int main() {
	int n, m;
	int num[MAXN];
	int num2[MAXN];
	cout << "input n,m: ";
	cin >> n >> m;
	partition(n, m, num, 0);
	cout << result << endl;
	cout << partition_memo(n, m) << endl;
	cout << partition2(n);
}