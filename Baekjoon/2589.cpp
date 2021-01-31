#include <iostream>
#include <queue>
#define MAX 60
using namespace std;
int H, W;
char map[MAX][MAX];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
int ans;
bool is_inside(int y, int x) {
	return y >= 0 && y < H && x >= 0 && x < W;
}

void bfs(int y, int x) {
	int visit[MAX][MAX] = { 0 };
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (is_inside(ny, nx) && visit[ny][nx] == 0 && map[ny][nx] == 'L') {
				visit[ny][nx] = visit[cy][cx] + 1;
				q.push(make_pair(ny, nx));
				if (ans < visit[ny][nx]) {
					ans = visit[ny][nx];
				}
			}
		}
	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}