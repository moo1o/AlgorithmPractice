#include <cstdio>
#include <vector>
#include <queue>
#define MAX 105
using namespace std;

int N, M, K;
char map[MAX][MAX];
char target[MAX];
int len;
struct INFO {
	int y, x, idx, route;
};
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int visit[MAX][MAX][MAX*MAX];

bool is_inside(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs(int y, int x) {
	int ret = 0;
	
	visit[y][x][1] = 1;
	
	queue<INFO> q;
	q.push({ y,x, 0, 1});
	while (!q.empty()) {
		int y = q.front().y; 
		int x = q.front().x;	
		int idx = q.front().idx;
		int route = q.front().route;
		q.pop();
		if (target[idx+1] == '\0') {
			ret = route;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y;
			int nx = x;
			for (int j = 0; j <= K; j++) {
				ny += dy[i];
				nx += dx[i];
				if (is_inside(ny, nx) && map[ny][nx] == target[idx+1] && visit[ny][nx][route] == 0) {
					visit[ny][nx][route] = 1;
					q.push({ ny,nx, idx + 1, route });
					route++;
				}
			}
		}
	}
	
	return ret;
}



int main(void) {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);
	}
	scanf("%s", target);
	for (int i = 0; target[i] != '\0' ; i++) {
		len++;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == target[0]) {
				memset(visit, 0, sizeof(visit));
				ans += bfs(i, j);
			}
		}
	}
	

	printf("%d\n", ans);


	return 0;
}