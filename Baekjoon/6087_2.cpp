#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char map[101][101];
int d[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
pair<int, int> p[2];

int main() {
	int w, h;
	int cnt = 0, ret = 0;
	char tmp[101];
	scanf("%d %d", &w, &h);
	for (int i = 0; i<h; i++) {
		scanf("%s", tmp);
		for (int j = 0; j<w; j++) {
			map[i][j] = tmp[j];
			if (map[i][j] == 'C') {
				p[cnt].first = i;
				p[cnt++].second = j;
			}
			d[i][j] = -1;
		}
	}
	int sx, sy, ex, ey;
	tie(sx, sy) = p[0];
	tie(ex, ey) = p[1];
	queue<tuple<int, int, int> > q;
	q.push(make_tuple(0, sx, sy));
	d[sx][sy] = 0;
	while (!q.empty()) {
		int x, y, cnt;
		tie(cnt, x, y) = q.front();
		q.pop();
		if (x == ex && y == ey) {
			ret = cnt - 1;
			break;
		}
		for (int i = 0; i<4; i++) {
			int nx = x;
			int ny = y;
			while (true) {
				nx = nx + dx[i];
				ny = ny + dy[i];
				if (nx<0 || nx >= h || ny<0 || ny >= w) break;
				if (map[nx][ny] == '*') break;
				if (d[nx][ny]>cnt + 1 || d[nx][ny] == -1) {
					d[nx][ny] = cnt + 1;
					q.push(make_tuple(cnt + 1, nx, ny));
				}
			}
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%2d", d[i][j]);
		}
		printf("\n");
	}

	printf("%d\n", ret);

	return 0;
}