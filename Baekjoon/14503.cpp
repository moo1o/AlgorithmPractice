#include <iostream>
#define MAX 50
using namespace std;

enum {
	NORTH = 0,
	WEST =1,
	SOUTH = 2,
	EAST = 3
};

int N, M;
int map[MAX][MAX], ans;
int visit[MAX][MAX];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void print(int y, int x, int d) {
	int loc[MAX][MAX] = { 0 };
	loc[y][x] = d+1;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			printf("%2d", visit[i][j]);
		}
		printf(" ");
		for (int j = 0; j <= M; j++) {
			printf("%2d", loc[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//탐색 : 북쪽(0) -> 서쪽(1), 서쪽(1) -> 남쪽(2), 남쪽(2)->동쪽(3), 동쪽(3)->북쪽(0)
//후진 : 북쪽(0) <-> 남쪽(2), 서쪽(1) <-> 동쪽(3), 
void dfs(int y, int x, int d, int cnt) {
	//print(y, x, d);
	int nd = d;
	for (int i = 0; i < 4; i++) {
		nd = (nd + 1) % 4;
		int ny = y + dy[nd];
		int nx = x + dx[nd];
		if (visit[ny][nx] == 0 && map[ny][nx] == 0) {
			visit[ny][nx] = 1;
			dfs(ny, nx, nd, cnt + 1);
			return;
		}
	}
	
		
	if (nd == d) {
		int ny = y - dy[nd];
		int nx = x - dx[nd];
		if (map[ny][nx] == 0) {
			if (visit[ny][nx] == 0) {
				visit[ny][nx] = 1;
				dfs(ny, nx, nd, cnt + 1);
			}
			else
				dfs(ny, nx, nd, cnt);
		}
		else {
			if (ans < cnt)
				ans = cnt;
			return;
		}
	}
	return;
}


int main(void) {
	scanf("%d %d", &N, &M);
	int y, x, dir;
	scanf("%d %d %d", &y, &x, &dir);
	y++;
	x++;
	memset(map, 1, sizeof(map));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	//북서남동 순으로 만들기
	switch (dir) {
	case 1: //동쪽 -> 3
		dir = 3;
		break;
	case 3: //서쪽 -> 1
		dir = 1;
		break;
	}
	visit[y][x] = 1;
	dfs(y, x, dir, 1);

	printf("%d\n", ans);

	return 0;
}