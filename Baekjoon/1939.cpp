#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#define MAXN 10005
#define MAXM 100005
using namespace std;

int N, M, ans;
//int map[MAXN][MAXN];
int visit[MAXN] = { 0 };
vector<pair<int, int>> map[MAXN];
vector<int> w;
int st, ed;

bool bfs(int w) {
	queue<int> q;
	memset(visit, 0, sizeof(visit));
	q.push(st);
	visit[st] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		//for (int i = 1; i <= N; i++) {
			//if (visit[i]== 0 && map[x][i] >= w) {
		for (int i = 0; i < map[x].size(); i++) {
			if (visit[map[x][i].first] == 0 && map[x][i].second >= w) {
				q.push(map[x][i].first);
				visit[map[x][i].first] = 1;
				if (map[x][i].first == ed)
					return true;
			}
		}
	}
	return false;
}

void bsearch(int left, int right) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (bfs(w[mid])) {
			left = mid + 1;
			ans = w[mid];
		}
		else {
			right = mid - 1;
		}
	}
}

int main(void) {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		/*map[from][to] = cost;
		map[to][from] = cost;*/
		map[from].push_back({ to, cost });
		map[to].push_back({ from, cost });
		w.push_back(cost);
	}
	scanf("%d%d", &st, &ed);
	sort(w.begin(), w.end());
	//unique(w.begin(), w.end());
	
	bsearch(0, w.size() - 1);

	printf("%d\n", ans);

	return 0;
}