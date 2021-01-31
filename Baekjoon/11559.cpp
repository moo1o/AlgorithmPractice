#include <cstdio>
#define MAX 100000
char map[15][10];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
typedef struct POINT {
	int y, x;
}PT;
PT myQ[MAX];
int front = 0, rear = 0;
void push(PT data) {
	myQ[rear] = data;
	rear = (rear + 1) % MAX;
}
PT pop() {
	PT ret = myQ[front];
	front = (front + 1) % MAX;
	return ret;
}
bool is_empty() {
	return front == rear;
}

void drop() {
	char tmp[12] = { 0 };
	for (int j = 0; j < 6; j++) {
		int idx = 0;
		for (int i = 11; i >= 0; i--) {
			if (map[i][j] != '.') {
				tmp[idx++] = map[i][j];
			}
			map[i][j] = '.';
		}
		for (int i = 11, k=0; k<idx && i >= 0; i--, k++) {
			map[i][j] = tmp[k];
		}
	}
}

bool is_inside(int y, int x) {
	return y >= 0 && y < 12 && x >= 0 && x < 6;
}

int bfs(PT st) {
	int cnt = 1;
	int visit[15][10] = { 0 };
	push(st);
	visit[st.y][st.x] =1;
	while (!is_empty()) {
		PT now = pop();
		char c = map[now.y][now.x];
		for (int i = 0; i < 4; i++) {
			PT next = { now.y + dy[i], now.x + dx[i] };
			if (is_inside(next.y, next.x) && visit[next.y][next.x] == 0 && c == map[next.y][next.x]) {
				cnt++;
				visit[next.y][next.x] = 1;
				push(next);
			}
		}
	}
	if (cnt >= 4) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (visit[i][j] == 1) {
					map[i][j] = '.';
				}
			}
		}
		return 1;
	}
	return 0;
}

int main(void) {
	for (int i = 0; i < 12; i++) {
		scanf("%s", map[i]);
	}
	int ans = 0;
	int tmp = 0;
	do {
		ans = tmp;
		bool flag = false;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.') {
					if (bfs({ i,j }) == 1) {
						if (!flag) {
							flag = true;
							tmp++;
						}
					}
				}
			}
		}
		drop();
	} while (ans != tmp);
	
	printf("%d\n", ans);

	return 0;
}