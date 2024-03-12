#include <iostream>
using namespace std;

#define MAXN 100

int friend_count[MAXN], friends[MAXN][MAXN];
int min_cut = MAXN * MAXN, min_partition[MAXN];

void print_arr(int arr[], int arr_len) {
	for (int i = 0; i < arr_len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void evaluate_partition(int bit[], int n) {
	int cut = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < friend_count[i]; j++) {
			if (i < friends[i][j] && bit[i] != bit[friends[i][j]]) { //i<friends[i][j]는 중복으로 세는거 방지, bit[i]!=bit[friends[i]j]]는 친구인데 숫자가 다를 경우
				cut++;
			}
		}
	}
	if (cut < min_cut) {
		for (int i = 0; i < n; i++) {
			min_partition[i] = bit[i];
		}
		min_cut = cut;
	}
}

void comb2_partition(int bits[], int n, int k, int index) {
	if (k == 0) {
		for (int i = index; i < n; i++) {
			bits[i] = 0;
		}
		evaluate_partition(bits, n);
	}
	else if (index == n) {
		return;
	}
	else {
		bits[index] = 0;
		comb2_partition(bits, n, k, index + 1);
		bits[index] = 1;
		comb2_partition(bits, n, k-1, index + 1);
	}
}


int main() {
	int set[MAXN], n;
	cout << "input n: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << i << " : ";
		cin >> friend_count[i];
		for (int j = 0; j < friend_count[i]; j++) {
			cin >> friends[i][j];
		}
	}
	comb2_partition(set, n, n / 2, 0); //nCn/2로 한 후 최소 cut인거 출력하면 됨
	cout << "cut : " << min_cut << endl;
	print_arr(min_partition, n);
	return 0;
}
