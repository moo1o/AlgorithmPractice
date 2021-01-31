#include <iostream>
#include <memory.h>
#define MAX 5
using namespace std;
int N, M, ans;
int paper[MAX][MAX];
int visit[MAX][MAX];
int team[MAX*MAX];
pair<int, int> num[MAX*MAX];
int dy[] = { 0, 1 };
int dx[] = { 1, 0 };

bool is_inside(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

void dfs(int k) {
	if (k == (N * M)+1) {
		int ary[MAX*MAX] = { 0 };
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				ary[visit[i][j]] = ary[visit[i][j]] * 10 + paper[i][j];
			}
		}

		for (int i = 1; i <= N * M; i++) {
			sum += ary[i];
		}

		if (ans < sum)
			ans = sum;
		return;
	}
	int y = num[k].first;
	int x = num[k].second;
	if (visit[y][x] != 0) {
		team[k] = visit[y][x];
		dfs(k + 1);
	}
	else {
		team[k] = k;
		//visit[y][x] = k;
		int temp[MAX][MAX];
		memcpy(temp, visit, sizeof(visit));
		for (int i = 0; i < 2; i++) {
			int ny = y;
			int nx = x;
			while (true) {
				if (is_inside(ny, nx) && visit[ny][nx] == 0) {
					visit[ny][nx] = k;
					dfs(k + 1);
					ny += dy[i];
					nx += dx[i];
				}
				else
					break;
			}
			memcpy(visit, temp, sizeof(visit));
		}
	}
}

int main(void) {
	scanf("%d%d", &N, &M);
	int k = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &paper[i][j]);
			num[k] = make_pair(i, j);
			k++;
		}
	}
	dfs(1);

	printf("%d\n", ans);


	return 0;
}