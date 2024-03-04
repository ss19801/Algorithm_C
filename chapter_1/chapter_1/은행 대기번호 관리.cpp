/* 그냥 Queue를 이용했을때
#define QUEUE_CAPACITY 8
#include <iostream>
using namespace std;

int queue[QUEUE_CAPACITY];
int head = 0;
int tail = -1;
int queue_size = 0;

void enqueue(int n) {
	if (queue_size == QUEUE_CAPACITY) {
		cout << "queue full!" << endl;
		return;
	}
	tail++;
	queue_size++;
	queue[tail] = n;
}

int dequeue() {
	int r;
	if (queue_size == 0) {
		cout << "queue empty!" << endl;
		return 0;
	}
	r = queue[head];
	head++;
	queue_size--;
	return r;
}

int main() {
	int number, r;
	do {
		cout << "input number: ";
		cin >> number;
		if (number > 0) {
			enqueue(number);
		}
		if (number == 0) {
			r=dequeue();
			cout << r << endl;
		}
	} while (number >= 0);
	return 0;
}
*/

//원형 Queue 이용할 때

#define QUEUE_CAPACITY 8
#include <iostream>
using namespace std;

int queue[QUEUE_CAPACITY];
int head = 0;
int tail = -1;
int queue_size = 0;

void enqueue(int n) {
	if (queue_size == QUEUE_CAPACITY) {
		cout << "queue full!" << endl;
		return;
	}
	tail = (tail + 1) % QUEUE_CAPACITY;
	queue_size++;
	queue[tail] = n;
}

int dequeue() {
	int r;
	if (queue_size == 0) {
		cout << "queue empty!" << endl;
		return 0;
	}
	r = queue[head];
	head = (head + 1) % QUEUE_CAPACITY;
	queue_size--;
	return r;
}

int main() {
	int number, r;
	do {
		cout << "input number: ";
		cin >> number;
		if (number > 0) {
			enqueue(number);
		}
		if (number == 0) {
			r = dequeue();
			cout << r << endl;
		}
	} while (number >= 0);
	return 0;
}