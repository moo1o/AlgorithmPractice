#include <iostream>	
#include <cstdio>
#include <cstring>
#define MAX 1001
#define MOD 10007
using namespace std;

long long dp[MAX][MAX];
char input[MAX];
int len;

int main(void) {
	scanf("%s", input);

	len = strlen(input);
	


	for (int i = 0; i < len; i++) {
		dp[i][i] = 1;
		if (input[i] == input[i + 1])
			dp[i][i + 1] = 3;
		else
			dp[i][i + 1] = 2;
	}

	int left, right;

	for (int L = 2; L < len; L++) {
		for (left = 0; left < len; left++) {
			right = left + L;

			if (right > len)
				break;
			dp[left][right] = dp[left][right - 1] + dp[left + 1][right] - dp[left + 1][right - 1] + MOD;

			if (input[left] == input[right])
				dp[left][right] += dp[left + 1][right - 1] + 1;
			dp[left][right] %= MOD;
		}
	}

	printf("%lld\n", dp[0][len - 1]);

	return 0;
}
 