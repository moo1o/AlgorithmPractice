#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1005
#define MAX_M 100005
int N, M;
struct INFO {
	int from, to;
	int cost;
}info[MAX_M];
int p[MAX_N];

bool comp(INFO a, INFO b) {
	return a.cost < b.cost;
}

int Find(int x) {
	if (p[x] == x)
		return x;
	else
		return p[x] = Find(p[x]);
}

void Union(int y, int x) {
	y = Find(y);
	x = Find(x);
	p[y] = x;
}


int main(void) {
	while (true) {
		scanf("%d%d", &N, &M);
		if (N == 0 && M == 0)
			break;
		int sum = 0;
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &info[i].from, &info[i].to, &info[i].cost);
			sum += info[i].cost;
		}
		sort(info, info + M, comp);
		for (int i = 0; i < N; i++) {
			p[i] = i;
		}
		
		int cnt = 1;
		int ans = 0;
		for (int i = 0; cnt < N && i < M; i++) {
			if (Find(info[i].from) != Find(info[i].to)) {
				Union(info[i].from, info[i].to);
				cnt++;
				ans += info[i].cost;
			}
		}
		ans = sum - ans;
		printf("%d\n", ans);
	}
	return 0;
}