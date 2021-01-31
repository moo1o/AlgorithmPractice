#include <iostream>
#include <queue>

#define MAX 305

using namespace std;

int N, M;
int map[MAX][MAX];
int visit[MAX][MAX];
struct INFO {
	int y, x;
};
int dy[] = { 0, 1};
int dx[] = { 1, 0};

bool is_inside(int y, int x) {
	return y >= 0 && y <= N && x >= 0 && x <= M;
}

int main(void) {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	queue<INFO> q;
	q.push({ 1, 1});
	visit[1][1] = 1;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 2; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (is_inside(ny, nx)) {
				if (map[ny][nx] == 0) {
					if (visit[ny][nx] == 0 || (visit[ny][nx] < visit[y][x])) {
						visit[ny][nx] = visit[y][x];
						q.push({ ny,nx });
					}
				}
				else if(map[ny][nx] == 1){
					if (visit[ny][nx] == 0 || (visit[ny][nx] < visit[y][x]+1)) {
						visit[ny][nx] = visit[y][x] +1;
						q.push({ ny,nx });
					}
				}
			}
		}
	}

	if (!map[1][1])
		visit[N][M] -= 1;
	printf("%d\n", visit[N][M]);

	return 0;
}