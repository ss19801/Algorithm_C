#include <iostream>
using namespace std;
#include <set>

void print_arr(set<int>& arr) {
	for (int i : arr) {
		cout << i << " ";
	}
	cout << endl;
}

void subset(set<int> arr, int n, int index) {
	if (index == n) {
		print_arr(arr);
		return;
	}
	arr.insert(index);
	subset(arr, n, index + 1);
	arr.erase(index);
	subset(arr, n, index + 1);
}

#define MAXN 1000

int main() {
	set<int> set;
	int n;
	cout << "input n: ";
	cin >> n;
	subset(set, n, 0);
	return 0;
}