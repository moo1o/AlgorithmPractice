#include <cstdio>
#define MAX 1005
using namespace std;

int n;
int d[MAX];

int dfs(int n){
	int& ret = d[n];
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	if (ret != 0)
		return ret;

	return ret = (dfs(n - 1) + dfs(n - 2))%10007;
}


int main(void) {
	scanf("%d", &n);

	printf("%d\n", dfs(n));

	return 0;
}