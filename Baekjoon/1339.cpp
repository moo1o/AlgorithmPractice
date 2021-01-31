#include <cstdio>

using namespace std;

int N;
int N_alpha[26];
char input[15][15];
int check[26];
int use[10];
int ans;

void calc() {
	int A = 0;
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = 0; input[i][j] != '\0'; j++) {
			tmp *= 10;
			tmp += N_alpha[input[i][j] - 'A'];
		}
		A += tmp;
	}
	if (ans < A) {
		ans = A;
	}
}

void perm(int k) {
	if (k == 26) {
		calc();
		return;
	}
	if (check[k] == 0) {
		perm(k + 1);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (use[i] == 0) {
			N_alpha[k] = i;
			use[i] = 1;
			perm(k + 1);
			use[i] = 0;
		}
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", input[i]);
		for (int j = 0; input[i][j] != '\0'; j++) {
			check[input[i][j] - 'A'] = 1;
		}
	}

	perm(0);

	printf("%d\n", ans);
	
	return 0;
}