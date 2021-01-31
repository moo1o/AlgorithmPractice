#include <iostream>
#define MAX 1000000
using namespace std;
enum {
	push = 1,
	pop,
	_size,
	_empty,
	front,
	back
};
struct myQueue {
	int q[MAX];
	int _front;
	int _rear;
	myQueue() {
		_front = 0;
		_rear = 0;
	}
	void push(int in) {
		q[_rear++] = in;
		if (_rear == MAX) {
			_rear = 0;
		}
	}
	int pop() {
		if (_front != _rear) {
			return q[_front++];
		}
		else {
			return -1;
		}
	}
	int isEmpty() {
		return _front == _rear ? 1 : 0;
	}
	int isFull() {
		return (_front == 0 && _rear == MAX - 1) ? 1 : 0;
	}
	int size() {
		return _rear - _front;
	}
	int front() {
		if (_front != _rear)
			return q[_front];
		else
			return - 1;
	}
	int back() {
		if (_front != _rear)
			return q[_rear-1];
		else
			return -1;
	}
}mqueue;

int N;
char input[10];

bool _strcmp(char* a, const char* b) {
	while (*a != '\0') {
		if (*a != *b)
			return false;
		a++;
		b++;
	}
	if (*b != '\0')
		return false;
	return true;
}

int command(char* input) {
	if (_strcmp(input, "push")) {
		return 1;
	}
	else if (_strcmp(input, "pop")) {
		return 2;
	}
	else if (_strcmp(input, "size")) {
		return 3;
	}
	else if (_strcmp(input, "empty")) {
		return 4;
	}
	else if (_strcmp(input, "front")) {
		return 5;
	}
	else if (_strcmp(input, "back")) {
		return 6;
	}
}


int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		switch (command(input)) {
		case push:
			int a;
			scanf("%d", &a);
			mqueue.push(a);
			break;
		case pop:
			printf("%d\n", mqueue.pop());
			break;
		case _size:
			printf("%d\n", mqueue.size());
			break;
		case _empty:
			printf("%d\n", mqueue.isEmpty());
			break;
		case front:
			printf("%d\n", mqueue.front());
			break;
		case back:
			printf("%d\n", mqueue.back());
			break;
		}
	}
	return 0;
}