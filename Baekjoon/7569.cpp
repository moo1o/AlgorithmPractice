#include <iostream>
#include <queue>
#define MAX 105
using namespace std;

int M, N, H, zero, ans;
int input[MAX][MAX][MAX];
int visit[MAX][MAX][MAX];
int dy[] = {0, 1, 0, -1, 0, 0};
int dx[] = {1, 0, -1, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
struct PT {
	int z, y, x;
};

bool is_inside(int z, int y, int x) {
	return z >= 0 && z < H && y >= 0 && y < N && x >= 0 && x < M;
}

int main(void) {
	scanf("%d%d%d", &M, &N, &H);
	queue<PT> q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &input[i][j][k]);
				if (input[i][j][k] == 1)
					q.push({ i, j, k });
				else if (input[i][j][k] == 0)
					zero++;
			}
		}
	}
	while (!q.empty()) {
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (is_inside(nz, ny, nx) && input[nz][ny][nx] == 0) {
				zero--;
				input[nz][ny][nx] = 1;
				visit[nz][ny][nx] = visit[z][y][x] + 1;
				if (ans < visit[nz][ny][nx])
					ans = visit[nz][ny][nx];
				q.push({ nz, ny, nx });
			}
		}
	}

	if (zero == 0) {
		printf("%d\n", ans);
	}
	else {
		printf("%d\n", -1);
	}


	return 0;
}