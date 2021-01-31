#include <cstdio>
#include <queue>
#include <memory.h>
#include <vector>
#include <set>
#define MAX 12
using namespace std;
int N, M, ans;
int map[MAX][MAX];
int temp[MAX][MAX];
struct PT {
	int y, x;
}loc[MAX*MAX], virus[MAX];
int vsize, zero;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool is_inside(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

void bfs() {
	queue<PT> q;
	int visit[MAX][MAX] = { 0 };
	for (int i = 0; i < vsize; i++) {
		q.push(virus[i]);
		visit[virus[i].y][virus[i].x] = 1;
	}
	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (is_inside(ny, nx) && map[ny][nx] == 0 && visit[ny][nx] == 0) {
				visit[ny][nx] = 1;
				cnt++;
				if (ans > (zero - cnt)) return;
				q.push({ ny, nx });
			}
		}
	}
	if (ans < (zero - cnt))
		ans = zero - cnt;
}

int main(void) {
	scanf("%d%d", &N, &M);

	int idx = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			
			if (map[i][j] == 2) {
				virus[vsize].y = i;
				virus[vsize].x = j;
				vsize++;
			}
			else if (map[i][j] == 0) {
				loc[idx].y = i;
				loc[idx].x = j;
				idx++;
				zero++;
			}
		}
	}
	zero -= 3;
	set<vector<int>> s;
	for (int i = 1; i < idx-2; i++) {
		for (int j = 1; j < idx-1; j++) {
			if (i == j) continue;
			for (int k = 1; k < idx; k++) {
				if (i== k || j == k) continue;
				vector<int> v;
				v.push_back(i);
				v.push_back(j);
				v.push_back(k);
				sort(v.begin(), v.end());
				if (s.find(v) != s.end()) {
					continue;
				}
				s.insert(v);
				map[loc[i].y][loc[i].x] = 1;
				map[loc[j].y][loc[j].x] = 1;
				map[loc[k].y][loc[k].x] = 1;
				bfs();
				map[loc[i].y][loc[i].x] = 0;
				map[loc[j].y][loc[j].x] = 0;
				map[loc[k].y][loc[k].x] = 0;
				
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}