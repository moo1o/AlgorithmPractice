#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[51];
int B[51];

bool comp(const int& a, const int& b) {
	return a > b;
}

int main(void){
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	sort(A, A + N, comp);
	sort(B, B + N);
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		ans += A[i] * B[i];
	}

	printf("%d\n", ans);
	return 0;
}