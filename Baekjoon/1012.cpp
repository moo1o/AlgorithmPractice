#include <cstdio>
#define MAX 55
#define QSIZE 1000000

int N, M, K;
int map[MAX][MAX];
int visit[MAX][MAX];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
typedef struct POINT {
	int y, x;
}PT;
PT myQ[QSIZE];
int front = 0, rear = 0;
void push(PT data) {
	myQ[rear] = data;
	rear = (rear + 1) % QSIZE;
}
PT pop() {
	PT ret = myQ[front];
	front = (front + 1) % QSIZE;
	return ret;
}
bool is_empty() {
	return front == rear;
}

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}
bool is_inside(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

void bfs(PT st) {
	push(st);
	visit[st.y][st.x] = 1;
	while (!is_empty()){
		PT data = pop();
		for (int i = 0; i < 4; i++) {
			PT next = { data.y + dy[i], data.x + dx[i] };
			if (is_inside(next.y, next.x) && map[next.y][next.x] == 1 && visit[next.y][next.x] == 0) {
				visit[next.y][next.x] = 1;
				push(next);
			}
		}
	}
}


int main(void) {
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		init();
		scanf("%d%d%d", &N, &M, &K);
		for (int i = 0; i < K; i++) {
			int y, x;
			scanf("%d%d", &x, &y);
			map[y][x] = 1;
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visit[i][j] == 0 && map[i][j] == 1) {
					bfs({i, j});
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}