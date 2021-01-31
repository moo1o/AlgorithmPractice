#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100005
#define MAXKM 1005
using namespace std;

int N, K, M;
int visit[MAXN + MAXKM];
vector<int> E[MAXN + MAXKM];
queue<int> q;

int main(void) {
	scanf("%d%d%d", &N, &K, &M);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			int in;
			scanf("%d", &in);
			E[N + 1 + i].push_back(in);
			E[in].push_back(N + 1 + i);
		}
	}

	visit[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int station = q.front();
		q.pop();
		for (int i = 0; i < E[station].size(); i++) {
			if (visit[E[station][i]] == 0) {
				q.push(E[station][i]);
				visit[E[station][i]] = visit[station]+1;
				
			}
		}
	}
	if (visit[N] == 0) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", (visit[N]) / 2 + 1);
	}

	return 0;
}