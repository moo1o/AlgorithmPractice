#include <iostream>
#define MAX 55
#define MAX_L 20
using namespace std;

int N, K, ans = 0;
char input[MAX][MAX_L];
int word[27] = { 0 };
void func() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		bool know = true;
		for (int j = 0; input[i][j] != '\0'; j++) {
			if (word[input[i][j] - 'a'] == 0) {
				know = false;
				break;
			}
		}
		if (know)
			cnt++;
	}
	if (cnt > ans)
		ans = cnt;
}


void comb(int n, int r, int cnt, int k) {
	if (r == cnt) {
		func();
		return;
	}
	if (n == k) {
		return;
	}
	else {
		comb(n, r, cnt, k + 1);
		if (word[k] != 1) {
			word[k] = 1;
			comb(n, r, cnt + 1, k + 1);
			word[k] = 0;
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%s", input[i]);
	}

	word['a' - 'a'] = 1;
	word['n' - 'a'] = 1;
	word['t' - 'a'] = 1;
	word['i' - 'a'] = 1;
	word['c' - 'a'] = 1;
	if (K>4)
		comb(26, K, 5, 0);
	printf("%d\n", ans);

	return 0;
}