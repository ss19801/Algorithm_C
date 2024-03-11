#include <iostream>
using namespace std;


int max_consecutive_sum(int s[], int n) { // 삼중루프 사용->직관적, 하지만 너무 오래걸림
	int sum, max_sum = s[0];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum = 0;
			for (int k = i; k <= j; k++) {
				sum = s[k];
			}
			if (sum > max_sum) {
				max_sum = sum;
			}
		}
	}
	return max_sum;
}

int max_consecutive_sum2(int s[], int n) {
	int sum, max_sum = s[0];
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += s[j];
			if (sum > max_sum) {
				max_sum = sum;
			}
		}
	}
	return max_sum;
}

/*
Mn-> 수열 s[0],...,s[n-1]의 연속부분수열의 합 중 최대
M'n-> 수열 s[0],....,s[n-1]이 있을 때, s[n-1]을 포함하는 연속부분수열 중 최대

두 가지 법칙이 성립한다(점화식)
M'1=s[0]
n>1이면 M'n=max(M'n-1+s[n-1],s[n-1])

M1=s[0]
n>1이면 Mn=max(M'n,Mn-1)
*/

int max(int a, int b) {
	return a > b ? a : b;
}

int max_sum2(int s[], int n) { //M'n
	if (n == 1) {
		return s[0];
	}
	return max(max_sum2(s, n - 1) + s[n - 1], s[n - 1]);
}

int max_sum1(int s[], int n) {
	if (n == 1) {
		return s[0];
	}
	return max(max_sum2(s,n), max_sum1(s,n - 1));
}

//dp 적용
#define N 1000
int c[N];

void calculate_max_consecutive_sum(int s[], int n) {
	int i;
	c[0] = s[0];
	for (int i = 1; i < n; i++) {
		c[i] = max(s[i], s[i] + c[i - 1]);
	}
}

int find_max_consecutive_sum(int s[], int n) {
	if (n == 1) {
		return s[0];
	}
	return max(c[n - 1], find_max_consecutive_sum(s, n - 1));
}

/*
재귀호출 X
Mn=max(M'n,Mn-1)
  =max(M'n,max(M'n-1,Mn-2))=max(M'n,M'n-1,Mn-2)
  =max(M'n,M'n-1,...,M'1)
*/

int find_max_consecutive_sum2(int s[], int n) {
	int max_sum = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] > max_sum) {
			max_sum = c[i];
		}
	}
	return max_sum;
}

int main() {
	return 0;
}