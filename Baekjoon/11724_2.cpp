#include <iostream>
#include <queue>
#define MAX 1005
using namespace std;


int N, M;
int map[MAX][MAX];
queue<int> q;
int visit[MAX];

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		map[a][b] = 1;
		map[b][a] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			cnt++;
			q.push(i);
			while (!q.empty()) {
				int x = q.front();
				q.pop();

				for (int j = 1; j <= N; j++) {
					if (visit[j]== 0 && map[x][j] == 1) {
						q.push(j);
						visit[j] = 1;
					}
				}
			}
		}
	}

	printf("%d\n", cnt);



	return 0;
}