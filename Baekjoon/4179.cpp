#include <iostream>
#include <queue>
#define MAX_SZ 1005
using namespace std;
int T, R, C;
char map[MAX_SZ][MAX_SZ];
int dx[] = { 1, 0 , -1, 0 };
int dy[] = { 0, 1, 0, -1 };
struct POINT {
	int y;
	int x;
}f, s;
queue<POINT> q;
int check_f[MAX_SZ][MAX_SZ];
int check_s[MAX_SZ][MAX_SZ];
int ans;

void init() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			check_f[i][j] = 0;
			check_s[i][j] = 0;
		}
	}
}

bool is_inside(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

void bfs() {
	//fire
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (is_inside(ny, nx) && (map[ny][nx] == 'J' || map[ny][nx] == '.')) {
				if (check_f[ny][nx] == 0 || check_f[ny][nx] > check_f[y][x] + 1) {
					check_f[ny][nx] = check_f[y][x] + 1;
					POINT tmp;
					tmp.y = ny;
					tmp.x = nx;
					q.push(tmp);
				}
			}
		}
	}

	q.push(s);
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (is_inside(ny, nx)) {
				if (map[ny][nx] == '.' && (check_s[ny][nx] == 0 || check_s[ny][nx] > check_s[y][x] + 1)) {
					check_s[ny][nx] = check_s[y][x] + 1;
					POINT tmp;
					tmp.y = ny;
					tmp.x = nx;
					q.push(tmp);
				}
			}
			else {
				if (check_f[y][x] == 0 || check_s[y][x] < check_f[y][x]) {
					if (ans == -1 || ans > check_s[y][x] + 1)
						ans = check_s[y][x] + 1;
				}

			}
		}
	}
}

int main(void) {
	//ios::sync_with_stdio(false);
	
	
	init();
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				s.y = i;
				s.x = j;
			}
			else if (map[i][j] == 'F') {
				f.y = i;
				f.x = j;
				q.push(f);
			}
		}
	}
	ans = -1;

	bfs();
	if (ans == -1)
		printf("IMPOSSIBLE\n");
	else {
		printf("%d\n", ans);
	}
	


	return 0;
}