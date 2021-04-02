#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
int dp[2002][2002];

void init(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}
}

int solution(int S, int E) {
	int L = S - 1;
	int R = E - 1; 
	while (L < R) {
		if (dp[L][R] != -1) {
			return dp[L][R];
		}
		if (v[L] != v[R]) {
			dp[L][R] = 0;
			return dp[L][R];
		}
		L++;
		R--;
	}
	dp[S - 1][E - 1] = 1;
	return dp[S - 1][E - 1];
}

int main(void) {
	scanf("%d", &N);
	init(N);
	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		v.push_back(input);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int S, E;
		scanf("%d%d", &S, &E);
		printf("%d\n", solution(S, E));
	}

	return 0;
}