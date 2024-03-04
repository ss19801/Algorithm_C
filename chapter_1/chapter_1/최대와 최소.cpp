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


//생각해보기
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
#define min(x,y) ((x)<(y)?(x):(y)) //실수 하면 오류 찾기 힘들고, 시간 오래걸릴 수도 있음.

int main() {
	return 0;
}