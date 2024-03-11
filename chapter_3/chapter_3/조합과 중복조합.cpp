#include <iostream>
using namespace std;

void print_arr(int set[], int set_size) {
	for (int i = 0; i < set_size; i++) {
		cout << set[i] << " ";
	}
	cout << endl;
}
//조합
void comb(int set[], int set_size, int n, int k, int index) {
	if (k == 0) {
		print_arr(set, set_size);
	}
	else if (index == n) {
		return;
	}
	else {
		set[set_size] = index; 
		comb(set, set_size + 1, n, k - 1, index + 1); //index를 포함
		comb(set, set_size, n, k, index + 1); //index를 미포함
	}
}

//이진수 조합
void comb2(int bits[], int n, int k, int index) {
	if (k == 0) {
		for (int i = index; i < n; i++) {
			bits[i] = 0;
		}
		print_arr(bits, n);
	}
	else if (index == n) {
		return;
	}
	else {
		bits[index] = 0;
		comb2(bits, n, k, index + 1);
		bits[index] = 1;
		comb2(bits, n, k-1, index + 1);
	}
}

//중복조합
void rcomb(int set[], int set_size, int n, int k, int index) {
	if (k == 0) {
		print_arr(set, set_size);
	}
	else if (index == n) {
		return;
	}
	else {
		set[set_size] = index;
		rcomb(set, set_size + 1, n, k - 1, index); //index를 포함하는 경우
		rcomb(set, set_size, n, k, index + 1); //index를 미포함하는 경우
	}
}

#define MAXN 100

int main() {
	int set[MAXN], n, k;
	int bits[MAXN];
	int rset[MAXN];
	int rbits[MAXN];
	cout << "input n,k: ";
	cin >> n >> k;
	cout << "집합" << endl;
	comb(set, 0, n, k, 0);
	cout << "2진수로 나타낸 집합" << endl;
	comb2(bits, n, k, 0);
	cout << "조합" << endl;
	rcomb(rset, 0, n, k, 0);
}