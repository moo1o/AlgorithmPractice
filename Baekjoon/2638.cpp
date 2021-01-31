#include <iostream>
#include <queue>
#define MAX 105
#define mf make_pair
using namespace std;

int N, M;
int map[MAX][MAX];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool is_inside(int y, int x) {
	return x >= 0 & x < M && y >= 0 && y < N;
}

int main(void) {
	scanf("%d%d", &N, &M);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				cnt++;
		}
	}
	int ans = 0;
	queue<pair<int, int>> q;
	while (cnt != 0) {
		ans++;
		int visit[MAX][MAX] = { 0 };
		q.push(mf(0, 0));
		visit[0][0] = 1;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (is_inside(ny, nx) && visit[ny][nx] == 0) {
					if (map[ny][nx] !=0) {
						map[ny][nx]++;
					}
					else {
						q.push(mf(ny, nx));
						visit[ny][nx] = 1;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%2d", map[i][j]);
				if (map[i][j] > 2) {
					map[i][j] = 0;
					cnt--;
				}
				if (map[i][j] == 2)
					map[i][j] = 1;
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("%d\n", ans);
	return 0;
}