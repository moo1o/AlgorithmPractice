#include <cstdio>
using namespace std;

int slec[10];
int chk[10];

void comb(int n, int cnt, int k, int m) {
	if (cnt == m) {
		for (int i=0; i < m; i++) {
			printf("%d ", slec[i]);
		}
		printf("\n");
		return;
	}
	if (k == n) {
		return;
	}
	chk[k] = 1;
	slec[cnt] = k + 1;
	comb(n, cnt + 1, k + 1, m);
	chk[k] = 0;
	comb(n, cnt, k + 1, m);
}

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	comb(N, 0, 0, M);

	return 0;
}