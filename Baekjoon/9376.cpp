#include <iostream>
#include <queue>
using namespace std;

struct INFO{
	int y, x, cnt;
};
int h, w, ans;
INFO pt[2];
char map[101][101];
int visit[101][101];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

void init_visit() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			visit[i][j] = 0;
		}
	}
}

bool is_inside(int y, int x) {
	return y >= 0 && y < h && x >= 0 && x < w;
}

void func() {
	init_visit();
	queue<INFO> q;
	q.push(pt[0]);
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny == pt[1].y && nx == pt[1].x) {
				pt[1].cnt += pt[0].cnt;
				while (!q.empty()) {
					q.pop();
				}
				break;
			}
			if (is_inside(ny, nx) && map[ny][nx] != '*' && visit[ny][nx] == 0) {
				visit[ny][nx] = 1;
				if (map[ny][nx] == '#') {
					map[ny][nx] = '.';
					q.push({ ny, nx, cnt + 1 });
				}
				else {
					q.push({ ny, nx, cnt });
				}
			}
		}
	}
	init_visit();
	q.push(pt[1]);
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (!is_inside(ny, nx)) {
				if (ans == -1 || ans > cnt)
					ans = cnt;
				continue;
			}

			if (map[ny][nx] != '*' && visit[ny][nx] == 0) {
				visit[ny][nx] = 1;
				if (map[ny][nx] == '#') {
					map[ny][nx] = '.';
					q.push({ ny, nx, cnt + 1 });
				}
				else {
					q.push({ ny, nx, cnt });
				}
			}
		}
	}
}


int main(void) {
	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		ans = -1;
		cin >> h >> w;
		int idx = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '$') {
					map[i][j] == '.';
					pt[idx].y = i;
					pt[idx].x = j;
					pt[idx].cnt = 0;
					idx++;
				}
			}
		}
		func();
		cout << ans << endl;
	}

	return 0;
}