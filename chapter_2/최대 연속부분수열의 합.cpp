#include <iostream>
using namespace std;


int max_consecutive_sum(int s[], int n) { // ���߷��� ���->������, ������ �ʹ� �����ɸ�
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
Mn-> ���� s[0],...,s[n-1]�� ���Ӻκм����� �� �� �ִ�
M'n-> ���� s[0],....,s[n-1]�� ���� ��, s[n-1]�� �����ϴ� ���Ӻκм��� �� �ִ�

�� ���� ��Ģ�� �����Ѵ�(��ȭ��)
M'1=s[0]
n>1�̸� M'n=max(M'n-1+s[n-1],s[n-1])

M1=s[0]
n>1�̸� Mn=max(M'n,Mn-1)
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

//dp ����
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
���ȣ�� X
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