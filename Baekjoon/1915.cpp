#include <cstdio>
#define MAX 1002
int M, N;
int map[MAX][MAX];
int cache[MAX][MAX];
int L;

int min(int a, int b, int c) {
	if (a > b) {
		if (b > c) {
			return c;
		}
		else
			return b;
	}
	else if (a > c) {
		return c;
	}
	return a;
}


int main(void) {
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);

			if (map[i][j] == 1) {
				cache[i][j] = min(cache[i - 1][j - 1], cache[i - 1][j], cache[i][j - 1]) + 1;
			}

			if (cache[i][j] > L)
				L = cache[i][j];
		}
	}

	printf("%d\n", L*L);

	return 0;
}