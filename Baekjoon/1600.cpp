#include <iostream>
#include <queue>
#include <memory.h>
#define MAX 205
using namespace std;

int K, W, H, ans;
int map[MAX][MAX];
int visit[MAX][MAX][35];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
pair<int, int> hrs[] = { {1, -2}, {2, -1}, {1, 2}, {2, 1}, { -1, -2 }, {-2, -1}, {-1, 2}, {-2, 1} };
struct INFO {
	int y, x, cnt, chance;
};

bool is_inside(int y, int x) {
	return y > 0 && y <= H && x > 0 && x <= W;
}

int main(void) {
	scanf("%d", &K);
	scanf("%d%d", &W, &H);

	memset(map, -1, sizeof(map));
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	queue<INFO> q;
	q.push({ 1, 1, 0, K});
	visit[1][1][0] = 1;
	visit[1][1][1] = K;
	ans = -1;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int chance = q.front().chance;
		int cnt = q.front().cnt;
		q.pop();
		
		if (y == H && x == W) {
			if (ans == -1 || ans > cnt)
				ans = cnt;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (visit[ny][nx][chance] == 0 && map[ny][nx] == 0) {
				visit[ny][nx][chance] = 1;
				q.push({ny, nx, cnt + 1, chance});
			}
		}
		
		for (int i = 0; chance > 0 && i < 8; i++) {
			int ny = y + hrs[i].second;
			int nx = x + hrs[i].first;
			if (is_inside(ny,nx) && visit[ny][nx][chance-1]== 0 && map[ny][nx] == 0) {
				visit[ny][nx][chance-1] = 1;
				q.push({ ny, nx, cnt+1, chance - 1 });
				
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}