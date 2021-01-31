#include <iostream>
#define MAX 55
using namespace std;

int N;
char map[MAX][MAX];
struct INFO {
	int y, x;
}B[3], E[3];



int main(void) {
	scanf("%d", &N);
	int ib = 0, ie = 0;
	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'B') {
				B[ib].y = i;
				B[ib].x = j;
				ib++;
			}
			if (map[i][j] == 'E') {
				B[ie].y = i;
				B[ie].x = j;
				ie++;
			}
		}
	}



	return;
}