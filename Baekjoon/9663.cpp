#include <iostream>
#define MAX 16
using namespace std;

int N;
int ans;
int visit[MAX];
int map[MAX][MAX];

bool check(int i, int j) {
	int k = i - 1;
	int j1 = j + 1;
	int j2 = j - 1;
	while (true) {
		if (k == 0 || j1 == N)
			break;
		if (map[k][j1])
			return false;
		k--;
		j1++;
	}
	k = i - 1;
	while (true) {
		if (k == 0 || j2 == -1)
			break;
		if (map[k][j2])
			return false;
		k--;
		j2--;
	}
	
	return true;
}

void func(int k) {
	if (k == N+1) {
		ans++;
		/*for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N; j++) {
		printf("%2d", map[i][j]);
		}
		printf("\n");
		}
		printf("\n");*/
		return;
	}
	for (int i = 0; i < N; i++) {
		/*map[k][i] = 1;
		func(k + 1);
		map[k][i] = 0;*/
		if (visit[i] == 0 && check(k, i)) {
			visit[i] = 1;
			map[k][i] = 1;
			func(k + 1);
			visit[i] = 0;
			map[k][i] = 0;
		}
	}
}

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		map[1][i] = 1;
		func(2);
		visit[i] = 0;
		map[1][i] = 0;
	}
	

	printf("%d\n", ans);

	return 0;
}