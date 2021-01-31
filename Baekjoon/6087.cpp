#include <iostream>
#include <queue>
#include <memory.h>
#include <tuple>
#define MAX 105
using namespace std;

int W, H, ans;
char input[MAX][MAX];
pair<int, int> mirror[2];
int visit[MAX][MAX];
int tmp[MAX][MAX];
int dy[] = { 0, 1, 0 , -1 };
int dx[] = { 1, 0, -1, 0 };

void print() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%2d", visit[i][j]);
		}
		
		
		printf("\n");
	}
	printf("\n");
}

bool is_inside(int y, int x) {
	return y >= 0 && y < H && x >= 0 && x < W;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push(mirror[0]);
	
	visit[mirror[0].first][mirror[0].second] = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4; i++) {
			int ny = y;
			int nx = x;
			while (true) {
				ny = ny + dy[i];
				nx = nx + dx[i];
				if (is_inside(ny, nx) && input[ny][nx] != '*') {
					if (visit[ny][nx] == -1 || visit[ny][nx] > visit[y][x] + 1) {
						visit[ny][nx] = visit[y][x] + 1;
						q.push({ ny, nx });
					}
				}
				else {
					break;
				}
			}
		}
	}
	print();
}

int main(void) {
	scanf("%d%d", &W, &H);
	int idx = 0;
	for (int i = 0; i < H; i++) {
		scanf("%s", input[i]);
		for (int j = 0; j < W; j++) {
			if (input[i][j] == 'C') {
				mirror[idx++] = make_pair(i, j);
			}
			visit[i][j] = -1;
		}
	}

	bfs();
	printf("%d\n", visit[mirror[1].first][mirror[1].second]-1);

	return 0;
}