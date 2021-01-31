#include <cstdio>
#include <memory.h>
#define MAX 105
using namespace std;

int N, M, K;
char map[MAX][MAX];
char target[MAX];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int dp[MAX][MAX][MAX];

bool is_inside(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int dfs(int y, int x, int k) {
	if (target[k + 1] == '\0')
		return 1;
	int& ret = dp[y][x][k];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y;
		int nx = x;
		for (int j = 0; j < K; j++) {
			ny += dy[i];
			nx += dx[i];
			if (is_inside(ny, nx) && target[k + 1] == map[ny][nx]) {
				ret += dfs(ny, nx, k + 1);
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

	int ans = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == target[0])
				ans += dfs(i, j, 0);
		}
	}


	printf("%d\n", ans);


	return 0;
}