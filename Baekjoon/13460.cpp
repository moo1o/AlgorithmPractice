#include <iostream>	
#include <queue>
#define MAX 15
using namespace std;

int N, M, ans;
char input[MAX][MAX];
struct INFO {
	int y, x;
	bool operator==(INFO comp) {
		return y == comp.y && x == comp.x;
	}
}B, R, O;
int visit[MAX][MAX][MAX][MAX];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

inline int _abs(int n){
	return n > 0 ? n : -n;
}

inline bool is_inside(INFO a) {
	return a.y >= 0 && a.y < N && a.x >= 0 && a.x < M;
}

bool move(INFO& r, INFO& b, int dir) {
	INFO tr = r;
	INFO tb = b;
	//빨간구슬 이동
	while (true) {
		tr.y += dy[dir];
		tr.x += dx[dir];
		if (!is_inside(tr) || input[tr.y][tr.x] != '.') {
			tr.y -= dy[dir];
			tr.x -= dx[dir];
			break;
		}else if(tr == O){
			break;
		}
	}
	//파란구슬 이동
	while (true) {
		tb.y += dy[dir];
		tb.x += dx[dir];
		if (!is_inside(tb) || input[tb.y][tb.x] != '.') {
			tb.y -= dy[dir];
			tb.x -= dx[dir];
			break;
		}
		else if (tb == O) {
			break;
		}
	}
	//방문했던 곳이거나 바뀌지 않으면 false;
	if ((visit[tr.y][tr.x][tb.y][tb.x] == 1) ||(tr == r && tb == b)) {
		return false;
	}
	else {
		if (tr == tb) {
			if (tr == O) {
				return false;
			}
			else if (r.y == b.y) {
				if (_abs(tr.x - r.x) > _abs(tb.x - b.x)) {
					tr.x -= dx[dir];
				}
				else {
					tb.x -= dx[dir];
				}
			}
			else if (r.x == b.x) {
				if (_abs(tr.y - r.y) > _abs(tb.y - b.y)) {
					tr.y -= dy[dir];
				}
				else {
					tb.y -= dy[dir];
				}
			}
		}
		else if (tb == O) {
			return false;
		}
		r = tr;
		b = tb;
		return true;
	}
}

void bfs() {
	queue<pair<INFO, INFO>> q;
	q.push({ R, B });
	visit[R.y][R.x][B.y][B.x] = 1;
	int cnt = 1;
	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			INFO r = q.front().first;
			INFO b = q.front().second;
			q.pop();
			for (int d = 0; d < 4; d++) {
				INFO nr = r;
				INFO nb = b;
				if (move(nr, nb, d)) {
					visit[nr.y][nr.x][nb.y][nb.x] = 1;
					if (nr == O) {
						ans = cnt;
						return;
					}
					q.push({ nr, nb });
				}
			}
		}
		cnt++;
		if (cnt == 11) {
			return;
		}
	}
}


int main(void) {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", input[i]);
		for (int j = 0; j < M; j++) {
			if (input[i][j] == 'B') {
				B = { i, j };
				input[i][j] = '.';
			}
			else if (input[i][j] == 'R') {
				R = { i, j };
				input[i][j] = '.';
			}
			else if (input[i][j] == 'O') {
				O = { i, j };
				input[i][j] = '.';
			}
		}
	}

	bfs();
	if (ans == 0)
		ans = -1;
	printf("%d\n", ans);

	return 0;
}