#include <iostream>
#include <queue>
#include <memory.h>
#define MAX 1005
using namespace std;

int H, W, N;
char map[MAX][MAX];
int visit[MAX][MAX];
pair<int, int> st;
char target = '1';
int cnt;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void search() {
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q; 
	q.push(st);
	visit[st.first][st.second] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (map[ny][nx] != 'X' && visit[ny][nx] < visit[y][x]) {
				if (map[ny][nx] == '.') {
					visit[ny][nx] = visit[y][x]+1;
					q.push({ ny, nx });
				}
				else if (map[ny][nx] <= target ) {
					cnt += (visit[y][x] + 1);
					target++;
				}
			}

		}
	}

}


int main(void) {
	ios::sync_with_stdio(false);

	cin >> H >> W >> N;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				st.first = i; 
				st.second = j;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		search();
	}

	cout << cnt << endl;

	return 0;
}