#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_X 1000000
#define MAX_T 200000
using namespace std;
/*
|a-x|≤2이고 |b-y|≤2이면 (x, y)에서 (a, b)로 이동할 수 있다
*/
int n, T;
vector<pair<int, int>> pt;
int visit[50002];

int _abs(int a) {
	return a > 0 ? a : -a;
}

int bfs() {
	queue<int> q;
	q.push(0);
	visit[0] = 1;
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		if (pt[idx].first == T)
			return visit[idx] - 1;

		for (int i = idx + 1; i <= n; i++) {
			if (_abs(pt[i].first - pt[idx].first) > 2)
				break;
			if (visit[i] == 0&&_abs(pt[i].second - pt[idx].second) < 3) {
				visit[i] = visit[idx] + 1;
				q.push(i);
			}
		}
		for (int i = idx - 1; i >= 0; i--) {
			if (_abs(pt[i].first - pt[idx].first) > 2)
				break;
			if (visit[i] == 0 && _abs(pt[i].second - pt[idx].second) < 3) {
				visit[i] = visit[idx] + 1;
				q.push(i);
			}
		}
	}
	return -1;
}

int main(void) {
	scanf("%d%d", &n, &T);
	pt.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		pt.push_back({ y,x });
	}
	sort(pt.begin(), pt.end());

	printf("%d\n", bfs());

	return 0;
}