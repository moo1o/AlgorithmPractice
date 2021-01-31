#include <cstdio>

int n, d;
int cnt;

int main(void) {
	scanf("%d%d", &n, &d);

	for (int i = 1; i <= n; i++) {
		int k = i;
		while (k) {
			if(k%10 == d){
				cnt++;
			}
			k /= 10;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
