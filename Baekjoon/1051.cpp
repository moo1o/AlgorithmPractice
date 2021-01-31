#include <cstdio>	
#define MAX 51
#define min(a, b) (a<b)?a:b
using namespace std;

int N, M;
int map[MAX][MAX];
int ans;

int main(void) {
	scanf("%d %d", &N, &M);
	int msz = min(N, M);
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int sz = msz; ans == 0 && sz >= 1; sz--) {
		for (int i = 0; ans == 0 && i < N-sz+1; i++) {
			for (int j = 0; ans == 0 && j < M-sz+1; j++) {
				if (map[i][j] == map[i][j+sz-1]
					&& map[i][j] == map[i+sz-1][j]
					&& map[i][j] == map[i+sz-1][j+sz-1]) {
					ans = sz;
					break;
				}
			}
		}
	}

	printf("%d\n", ans*ans);

	return 0;
}