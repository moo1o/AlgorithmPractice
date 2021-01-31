#include <cstdio>
#include <algorithm>
using namespace std;
int all[10];
int check[10];
int real[8];
bool f = false;

void dfs(int k, int cnt, int h) {
	if (k == 9 || cnt == 7) {
		if (!f && h == 100 && cnt == 7) {
			f = true;
			int idx = 0;
			for (int i = 0; i < 9; i++) {
				if (check[i])
					real[idx++] = all[i];
			}
			sort(real, real + 7);
			for (int i = 0; i < 7; i++) {
				printf("%d\n", real[i]);
			}
		}
		return;
	}
	if (f || h > 100) {
		return;
	}
	check[k] = 0;
	dfs(k + 1, cnt, h);
	check[k] = 1;
	dfs(k + 1, cnt + 1, h + all[k]);
	//check[k] = 0;
}


int main(void) {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &all[i]);
	}

	dfs(0, 0, 0);

	return 0;
}