#include <iostream>
#include <queue>
#define MAX 105
#define mp make_pair
using namespace std;
int N;
int input[MAX][MAX];
int visit[MAX][MAX];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool is_inside(int y, int x) {
	return x >= 0 & x < N && y >= 0 && y < N;
}

void print(int visit[MAX][MAX]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%2d", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	scanf("%d", &N);
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j] == 1)
				q1.push(mp(i, j));
		}
	}
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (input[i][j] == 1 && visit[i][j]==0) {
				q2.push(mp(i, j));
				input[i][j] = cnt;
				visit[i][j] = 1;
				while (!q2.empty()) {
					int y = q2.front().first;
					int x = q2.front().second;
					q2.pop();
					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (is_inside(ny, nx) && input[ny][nx] == 1 && visit[ny][nx] == 0) {
							visit[ny][nx] = 1;
							input[ny][nx] = cnt;
							q2.push(mp(ny, nx));
						}
					}
				}
				cnt++;
			}

		}
	}

	int ans = 0;
	
	while (!q1.empty()) {
		//print(visit);
		int y = q1.front().first;
		int x = q1.front().second;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (is_inside(ny, nx)) {
				if (visit[ny][nx] == 0 && input[ny][nx] == 0) {
					visit[ny][nx] = visit[y][x] + 1;
					input[ny][nx] = input[y][x];
					q1.push(mp(ny, nx));
				}
				else if(visit[ny][nx] != 0 && input[ny][nx] != input[y][x]) {
					if(ans == 0 || ans > visit[y][x] - 1 + visit[ny][nx] - 1)
						ans = visit[y][x] - 1 + visit[ny][nx] - 1;
					//break;
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}