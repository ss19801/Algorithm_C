#include <iostream>
using namespace std;

void right_rotate(int arr[], int s, int t) {
	int last = arr[t];
	for (int i = t; i > s; i--) {
		arr[i] = arr[i - 1];
	}
	arr[s] = last;
}

void left_rotate(int arr[], int s, int t) {
	int first = arr[s];
	for (int i = s; i < t; i++) {
		arr[i] = arr[i + 1];
	}
	arr[t] = first;
}

int main() {
	return 0;
}