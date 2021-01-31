#include <iostream>
#define MAX 30
using namespace std;

int N;
int S[MAX][MAX];
int team[MAX];


void permutation(int* team) {

}


int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &S[i][j]);
		}
	}


	return 0;
}