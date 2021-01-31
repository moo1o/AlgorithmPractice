#include <cstdio>
#include <queue>
#define MAX 1000005
using namespace std;

long long F, S, G, U, D;
long long check[MAX];

bool is_inside(long long x) {
	return x > 0 && x <= F;
}

void init() {
	for (long long i = 1; i <= F; i++) {
		check[i] = -1LL;
	}
}

int main(void) {
	scanf("%lld %lld %lld %lld %lld", &F, &S, &G, &U, &D);
	init();
	queue<long long> q;
	long long dx[2] = { U, -D };
	q.push(S);
	check[S] = 0;
	while (!q.empty()) {
		long long loc = q.front();
		q.pop();
		
		for (int i = 0; i < 2; i++) {
			long long next = loc + dx[i];
			if (is_inside(next) && check[next] == -1LL) {
				check[next] = check[loc] + 1LL;
				q.push(next);
			}
		}
	}
	//printf("F:%lld S:%lld G:%lld U:%lld D:%lld\n", F, S, G, U, D);
	//for (long long i = 1; i <= F; i++) {
	//	if (check[i] <check[i - 1]) {
	//		printf("check[%lld] : %lld\n", i-1, check[i-1]);
	//		printf("check[%lld] : %lld\n", i, check[i]);
	//	}
	//	printf("check[%lld] : %lld\n", i, check[i]);
	//}

	if (check[G] == -1)
		printf("use the stairs\n");
	else
		printf("%lld\n", check[G]);

	return 0;
}