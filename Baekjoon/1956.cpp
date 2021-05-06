#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct road {
	int from;
	int to;
	int len;
};

vector<road> ary;
int check[402][402] = {0};
int V, E;
int ans = 0;
bool comp(road a, road b) {
	return a.len < b.len;
}

void solution() {
	vector<int> route(V+1);
	for (int i = 0; i < E; i++) {
		if (check[ary[i].from][ary[i].to] == 0) {
			check[ary[i].from][ary[i].to] = ary[i].len;
			route[ary[i].from] = ary[i].to;
		}
	}
	
	vector<int> visit(V + 1);
	visit[1] = 1; 
	int cnt = 0;
	for (int i = 1; i <= V; i++) {
		if (route[i]) {
			visit[route[i]]++;
			cnt++;
			ans += check[i][route[i]];
		}
	}
	if (cnt == V + 1 && visit[1] == 2) {
		printf("%d\n", ans);
		return;
	}
	printf("-1\n");
	return;	
}




int main(void) {
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		ary.push_back({ a,b,c });
	}
	sort(ary.begin(), ary.end(), comp);
	solution();
	return 0;
}