#include <iostream>
#include <memory.h>
#include <queue>
#define MAX 1600
using namespace std;

int R, C, ans;
char map[MAX][MAX];
int watermap[MAX][MAX];
struct INFO {
	int y, x;
}SWAN[3];
int visit[MAX][MAX];
queue<INFO> ice;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool is_inside(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

bool meet(int limit) {
	memset(visit, 0, sizeof(visit));
	queue<INFO> s;
	s.push(SWAN[1]);
	visit[SWAN[1].y][SWAN[1].x] = 1;
	while (!s.empty()) {
		int y = s.front().y;
		int x = s.front().x;

		s.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (is_inside(ny, nx) && visit[ny][nx] == 0) {
				if (SWAN[2].y == ny && SWAN[2].x == nx) {
					return true;
				}
				else if (watermap[ny][nx] <= limit ) {
					visit[ny][nx] = 1;
					s.push({ ny, nx });
				}

			}
		}
	}
	return false;
}

int bfs() {
	int day = 0;
	
	while (!ice.empty()) {
		int i = ice.size();

		for (; i > 0; i--) {
			int y = ice.front().y;
			int x = ice.front().x ;
			ice.pop();
			
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (is_inside(ny, nx) && map[ny][nx] == 'X') {
					map[ny][nx] = '.';
					watermap[ny][nx] = day+1;
					ice.push({ ny, nx });
				}
			}
				
		}
		day++;
	}
	return day-1;
}

int main(void) {
	scanf("%d%d", &R, &C);
	
	int idx = 1;
	for (int i = 0; i < R; i++) {
		scanf("%s", &map[i]);
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '.') {
				for (int k = 0; k < 4; k++) {
					if(map[i+dy[k]][j+dx[k]] == 'X')
						ice.push({ i,j });
				}
			}
			else if (map[i][j] == 'L') {
				ice.push({ i,j });
				SWAN[idx].y = i;
				SWAN[idx].x = j;
				idx++;
			}
		}
	}
	
	int l = 0;
	int r = bfs();

	while (l <= r) {
		int mid = (l + r) / 2;
		if (meet(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}

	printf("%d\n", ans);

	return 0;
}