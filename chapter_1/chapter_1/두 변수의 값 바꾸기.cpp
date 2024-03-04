#include <iostream>
using namespace std;

void wrong_swap(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//배열의 두 원소 바꾸기
void swap_arr(int arr[], int i, int j) {
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main() {
	return 0;
}