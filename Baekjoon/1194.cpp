#include <iostream>
#include <queue>
#include <string>
#include <memory>
#define MAX 60
using namespace std;

struct INFO {
	int y, x, key;
};

int N, M;
string map[MAX];
pair<int, int> st, ed;
int visit[70][MAX][MAX];
queue<INFO> q;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int ans = 987654321;

bool is_inside(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}


void bfs() {
	q.push({st.first, st.second, 0});
	visit[0][st.first][st.second] = 0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int key = q.front().key;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (is_inside(ny, nx)&&visit[key][ny][nx] == 0) {
				if (map[ny][nx] >= 'a' && map[ny][nx] <= 'f') {
					visit[key][ny][nx] = visit[key][y][x] + 1;
					int nkey = key | (1 << (map[ny][nx] - 'a'));
					visit[nkey][ny][nx] = visit[key][y][x] + 1;
					q.push({ ny, nx, nkey });
				}
				else if (map[ny][nx] >= 'A' && map[ny][nx] <='F') {
					if (key & (1 << (map[ny][nx] - 'A'))) {
						visit[key][ny][nx] = visit[key][y][x] + 1;
						q.push({ ny, nx, key });
					}
				}
				else if (map[ny][nx] == '1') {
					if (ans > visit[key][y][x] + 1) {
						ans = visit[key][y][x] + 1;
						visit[key][ny][nx] = visit[key][y][x] + 1;
					}
				}
				else if (map[ny][nx] != '#') {
					visit[key][ny][nx] = visit[key][y][x] + 1;
					q.push({ ny, nx, key });
				}
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			//memset(visit, -1, sizeof(visit));
			if (map[i][j] == '0') {
				st = make_pair(i, j);
			}
			/*if (map[i][j] == '1') {
				ed = make_pair(i, j);
			}*/
		}
	}
	bfs();
	
	if (ans == 987654321)
		ans = -1;
	cout << ans << endl;

	return 0;
}