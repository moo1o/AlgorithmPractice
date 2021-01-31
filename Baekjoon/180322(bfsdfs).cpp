#include <cstdio>
#define MAX 1024
int myQueue[MAX];
int front = 0, rear = 0;
void push(int n) {
	myQueue[rear] = n;
	rear = (rear + 1) % MAX;
}
int pop() {
	front = (front + 1) % MAX;
	return myQueue[front - 1];
}
bool is_empty() {
	return front == rear;
}

int input[12][12] = { 0 };
int visit[12] = { 0 };
void bfs(int n) {
	/*
	1. 인접행렬(가중치)
	2. 간선배열(가중치)
	3. 지도(가중치)
	
	시작점 큐에 넣는다
	시작점 방문표시
	반복(큐가 빌때까지)
		큐에 하나 꺼낸다 -> t
		t와 연결된 노드 -> k
		k가 방문 안했으면(갈수있으면)
		k를 큐에 넣고 방문 -> t의 비용 + 이동비용 -> k 비용
	*/
	
	push(n);
	visit[n] = 1;
	while (!is_empty()) {
		int x = pop();
		printf("%d\n", x);
		
		for (int i = 1; i <= 7; i++) {
			if (visit[i] == 0 && input[x][i] == 1) {
				push(i);
				visit[i] = 1;
			}
		}
	}

	/*
	input
	8
	1 2
	1 3
	2 4	
	2 5
	4 6
	5 6
	6 7
	3 7
	*/

}

int main(void) {
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a, b;
			scanf("%d%d", &a, &b);
			input[a][b] = 1;
			input[b][a] = 1;
		}
	}
	bfs(2);

	return 0;
}