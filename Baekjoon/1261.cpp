#include <iostream>
#include <queue>
#define MAX 105
#define mf make_pair
using namespace std;

int N, M;
int map[MAX][MAX];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int visit[MAX][MAX];

bool is_inside(int y, int x) {
	return x >= 1 && x <= N && y >= 1 && y <= M;
}

void printvisit() {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%2d", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	scanf("%d %d", &N, &M);
	char input[MAX][MAX];
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
		scanf("%s", input[i]);
	}
	
	queue<pair<int, int>> q; 
	q.push(mf(1, 1));
	visit[1][1] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (is_inside(ny, nx)) {
				if (visit[ny][nx] == 0) {
					if (map[ny][nx] == 0)
						visit[ny][nx] = visit[y][x];
					else
						visit[ny][nx] = visit[y][x] + 1;
					q.push(mf(ny, nx));
				}
				else {
					if (map[ny][nx] == 0) {
						if (visit[ny][nx] > visit[y][x]) {
							visit[ny][nx] = visit[y][x];
							q.push(mf(ny, nx));
						}
					}
					else {
						if (visit[ny][nx] > visit[y][x]+1) {
							visit[ny][nx] = visit[y][x]+1;
							q.push(mf(ny, nx));
						}
					}
				}
			}
		}
	}

	printf("%d\n", visit[M][N] - 1);
	return 0;
}