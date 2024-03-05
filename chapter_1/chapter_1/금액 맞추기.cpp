#include <iostream>
using namespace std;

int pay(int money, int bills[], int n) {
	int count = 0;
	if (n == 1) {
		if (money % bills[0] == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int t = money / bills[n - 1];
	for (int i = 0; i <= t; i++) {
		count += pay(money - bills[n - 1] * i, bills, n - 1);
	}
	return count;
}

#define MAXN 50

int main() {
	int num_bills, money;
	int bills[MAXN];

	cout << "input number of bills: ";
	cin >> num_bills;
	cout << "input bills: ";
	for (int i = 0; i < num_bills; i++) {
		cin >> bills[i];
	}
	cout << "input money: ";
	cin >> money;
	cout << pay(money, bills, num_bills);
	return 0;
}