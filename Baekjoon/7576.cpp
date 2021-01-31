#include <iostream>
#include <queue>
#define MAX 1005
using namespace std;

int M, N;
int map[MAX][MAX];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
struct INFO {
	int y, x, day;
};
queue<INFO> q;

bool is_inside(int y, int x) {
	return x >= 0 && x < M && y >= 0 && y < N;
}

int main(void) {
	scanf("%d%d", &M, &N);
	int count = 0;
	for (int i = 1; i <= N; i++) {
		map[i][0] = -1;
		map[i][M+1] = -1;
		for (int j = 1; j <= M; j++) {
			map[0][j] = -1;
			map[N+1][j] = -1;
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				q.push({ i, j, 0 });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	int ans = 0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int day = q.front().day;
		if (ans < day)
			ans = day;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (map[ny][nx] == 0) {
				map[ny][nx] = 1; 
				q.push({ ny, nx, day + 1 });
			}
		}
	}

	for (int i = 1; ans != -1 && i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0) {
				ans = -1;
				break;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}