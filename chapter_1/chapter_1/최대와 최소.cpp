#include <iostream>
using namespace std;

int min(int x, int y) {
	if (x < y) {
		return x;
	}
	return y;
}

int max(int x, int y) {
	if (x > y) {
		return x;
	}
	return y;
}


//�����غ���
int max_three(int x, int y, int z) {
	int max = x;
	if (y > max) {
		max = y;
	}
	if (z > max) {
		max = z;
	}
	return max;
}

int max_arr(int arr[], int arr_len) {
	int maxa = arr[0];
	for (int i = 1; i < arr_len; i++) {
		if (arr[i] > maxa) {
			maxa = arr[i];
		}
	}
	return maxa;
}

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y)) //�Ǽ� �ϸ� ���� ã�� �����, �ð� �����ɸ� ���� ����.

int main() {
	return 0;
}