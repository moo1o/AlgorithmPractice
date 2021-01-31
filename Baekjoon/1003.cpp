#include <cstdio>

using namespace std;

int cnt[2];
int T;
int input;

int fibonacci(int n) {
	if (n == 0) {
		cnt[0]++;
		return 0;
	}
	else if (n == 1) {
		cnt[1]++;
		return 1;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main(void) {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &input);

		fibonacci(input);
		printf("%d %d\n", cnt[0], cnt[1]);
		cnt[0] = 0;
		cnt[1] = 0;
	}

	return 0;
}