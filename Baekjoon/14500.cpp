#include <iostream>
#define MAX 505
#define mf make_pair
using namespace std;

int N, M, ans;
int map[8][MAX][MAX];
pair<int, int> blk[5][4] = { 
	{mf(0,0),mf(0,1),mf(0,2),mf(0,3)},
{ mf(0,0),mf(0,1),mf(1,0),mf(1,1) },
{ mf(0,0),mf(1,0),mf(2,0),mf(2,1) },
{ mf(0,0),mf(1,0),mf(1,1),mf(2,1) },
{ mf(0,0),mf(0,1),mf(0,2),mf(1,1) } };


void init() {
	for (int k = 0; k < 8; k++) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				map[k][i][j] = -1;
			}
		}
	}
}

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main(void) {
	scanf("%d %d", &N, &M);
	init();
	int high = max(N, M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[0][i][j]);
			map[1][M-j+1][i] = map[0][i][j];
			map[2][N-i+1][M-j+1] = map[0][i][j];
			map[3][j][N-i+1] = map[0][i][j];
			map[4][i][M-j+1] = map[0][i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[5][M - j + 1][i] = map[4][i][j];
			map[6][N - i + 1][M - j + 1] = map[4][i][j];
			map[7][j][N - i + 1] = map[4][i][j];
		}
	}

	for (int k = 0; k < 8; k++) {
		for (int i = 1; i < high; i++) {
			for (int j = 1; j < high; j++) {
				for (int l = 0; l < 5; l++) {
					int cnt = 0;
					for (int m = 0; m < 4; m++) {
						if (map[k][i+blk[l][m].first][j + blk[l][m].second] == -1) {
							cnt = -1;
							break;
						}
						cnt += map[k][i + blk[l][m].first][j + blk[l][m].second];
					}
					if (ans < cnt)
						ans = cnt;
				}
			}
		}
	}
	printf("%d\n", ans);

	/*for (int k = 0; k < 8; k++) {
		for (int i = 1; i <= high; i++) {
			for (int j = 1; j <= high; j++) {
				printf("%3d", map[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}*/
	

	
	return 0;
}