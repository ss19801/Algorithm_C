#include <iostream>
#include <set>
using namespace std;
#define MAXN 100

int weight[MAXN], value[MAXN], capacity;
int max_value = 0;
set<int> max_set;

void print_arr(set<int> arr) {
	for (int i : arr) {
		cout << i << " ";
	}
	cout << endl;
}

void evaluate_knapsack(set<int>& arr) {
	int c_volume = 0, c_value = 0;
	for (int i : arr) {
		c_value += value[i];
		c_volume += weight[i];
	}
	if (c_volume > capacity) {
		return;
	}
	if (c_value > max_value) {
		max_value = c_value;
		max_set = arr;
	}
}

void subset_knapsack(set<int>& arr, int n, int index) {
	if (index == n) {
		evaluate_knapsack(arr);
		return;
	}
	arr.insert(index);
	subset_knapsack(arr, n, index + 1);
	arr.erase(index);
	subset_knapsack(arr, n, index + 1);
}

int main() {
	set<int> set;
	int n;
	cin >> n >> capacity;
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	subset_knapsack(set, n, 0);
	cout << "Max Value : " << max_value << endl;
	print_arr(max_set);
	return 0;
}


/*
10 20
2 3 3 4 4 5 7 8 8 9
3 5 7 4 3 9 2 9 5 10
*/