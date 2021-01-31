#include <iostream>
#define MAX 100005
#define ll long long
using namespace std;

int n;
ll input[MAX];
ll ans;
void func(int k, ll sum) {
	if (k == n) {
		if (sum > ans)
			ans = sum;
	}
	func(k + 1, sum);
	func(k + 1, sum+input[k]);
}

int main(void) {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &input[i]);
	}

	func(0, 0);

	printf("%lld\n", ans);

	return 0;
}