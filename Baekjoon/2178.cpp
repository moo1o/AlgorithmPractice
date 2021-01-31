#include <cstdio>
#define MAX 105
#define QSIZE 10050

int N, M;
int map[MAX][MAX] = { 0 };
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int visit[MAX][MAX] = { 0 };

typedef struct POINT {
	int y, x;
}POINT;
POINT myQueue[QSIZE];
int front=0, rear=0;
void push(POINT data) {
	myQueue[rear] = data;
	rear = (rear + 1) % QSIZE;
}
POINT pop() {
	POINT ret = myQueue[front];
	front = (front + 1) % QSIZE;
	return ret;
}
bool is_empty() {
	return front == rear;
}

int bfs() {
	push({ 1, 1 });
	visit[1][1] = 1;
	while (!is_empty()) {
		POINT data = pop();
		for (int i = 0; i < 4; i++) {
			POINT next = {data.y + dy[i], data.x + dx[i]};
			if (visit[next.y][next.x] == 0 && map[next.y][next.x] == 1) {
				visit[next.y][next.x] = visit[data.y][data.x]+1;
				if (next.y == N && next.x == M) {
					return visit[next.y][next.x];
				}
				push(next);
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	printf("%d\n", bfs());
	return 0;
}