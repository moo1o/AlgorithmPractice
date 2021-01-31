#include <iostream>
#define MAX 1000000
using namespace std;

enum {
	push = 1,
	pop,
	_size,
	_empty,
	top
};

struct myStack {
	int s[MAX];
	int top;

	myStack() {
		top = -1;
	}
	void push(int in) {
		s[++top] = in;
	}
	int pop() {
		if (top != -1) {
			return s[top--];
		}
		else
			return -1;
	}
	int isEmpty() {
		return top == -1 ? 1 : 0;
	}
	int peek() {
		if (top != -1)
			return s[top];
		else
			return -1;
	}
	int size() {
		return top + 1;
	}
}mstack;

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
	else if (_strcmp(input, "top")) {
		return 5;
	}
}


int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		//printf("%s", input);
		switch (command(input)) {
		case push:
			int a;
			scanf("%d", &a);
			mstack.push(a);
			break;
		case pop:
			printf("%d\n", mstack.pop());
			break;
		case _size:
			printf("%d\n", mstack.size());
			break;
		case _empty:
			printf("%d\n", mstack.isEmpty());
			break;
		case top:
			printf("%d\n", mstack.peek());
			break;
		}
	}
	
	return 0;
}