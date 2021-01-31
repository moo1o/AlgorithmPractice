#include <cstdio>
#define MAX 50
using namespace std;

int N, M;
char map[MAX][MAX];
char chmap1[MAX][MAX];
char chmap2[MAX][MAX];
int ans = 9876543;
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%c", chmap2[i][j]);
		}
		printf("\n");
	}
}

bool is_inside(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int check(int y1, int x1, int y2, int x2) {
	int cnt1=0, cnt2 = 0;
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			if (chmap1[i][j] != map[i][j])
				cnt1++;
			if (chmap2[i][j] != map[i][j])
				cnt2++;
		}
	}
	if (cnt1 < cnt2)
		return cnt1;
	else
		return cnt2;
}

int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &map[i][j]);
			if ((i+j) % 2 == 0) {
				chmap1[i][j] = 'W';
				chmap2[i][j] = 'B';
			}
			else {
				chmap1[i][j] = 'B';
				chmap2[i][j] = 'W';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = 9876543;
			if (is_inside(i + 7, j + 7)) {
				tmp = check(i, j, i + 7, j + 7);
				if (ans > tmp)
					ans = tmp;
			}
			else
				continue;
		}
	}
	printf("%d\n", ans);

	return 0;
}