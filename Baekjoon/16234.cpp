#include <iostream>
#include <queue>
#define MAX 60
using namespace std;

int N, L, R;
int map[MAX][MAX];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

bool is_inside(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < N;
}

int _abs(int n) {
	return n > 0 ? n : -n;
}

int bfs() {
	int move = 0;
	int visit[MAX][MAX] = { 0 };
	int man[MAX*MAX] = { 0 };
	int cnt[MAX*MAX] = { 0 };
	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				q.push(make_pair(i, j));
				visit[i][j] = num;
				man[num] = map[i][j];
				cnt[num]++;
				num++;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (is_inside(ny, nx) && visit[ny][nx] == 0) {
							int t = _abs(map[y][x] - map[ny][nx]);
							if (t >= L && t <= R) {
								visit[ny][nx] = visit[y][x];
								man[visit[y][x]] += map[ny][nx];
								cnt[visit[y][x]]++;
								q.push(make_pair(ny, nx));
								move = 1;
							}
						}
					}
				}
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//if(cnt[visit[i][j]] != 0)
			map[i][j] = man[visit[i][j]] / cnt[visit[i][j]];
		}
	}
	return move;
}

int solve() {
	int ret = 0; 
	int temp = 0;
	do{
		temp = ret;
		ret += bfs();
	} while (ret != temp);
	return ret;
}

int main(void) {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << solve() << endl;

	return 0;
}