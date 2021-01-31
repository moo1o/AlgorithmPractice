#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100005
using namespace std;

int N;
struct POINT {
	int num, x, y, z;
}plnt[MAX];
struct INFO {
	int from, to, cost;
};
int p[MAX];

bool compX(POINT a, POINT b) {
	return a.x < b.x;
}
bool compY(POINT a, POINT b) {
	return a.y < b.y;
}
bool compZ(POINT a, POINT b) {
	return a.z < b.z;
}
bool comp(INFO a, INFO b) {
	return a.cost < b.cost;
}

int find(int x) {
	if (p[x] == x)
		return p[x];
	else
		return p[x] = find(p[x]);
}
void uni(int y, int x) {
	y = find(y);
	x = find(x);
	p[y] = p[x];
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		plnt[i].num = i;
		scanf("%d %d %d", &plnt[i].x, &plnt[i].y, &plnt[i].z);
	}
	for (int i = 0; i < N; i++) {
		p[i] = i;
	}
	vector<INFO> ary;
	
	
	sort(plnt, plnt + N, compX);
	for (int i = 0; i < N - 1; i++) {
		ary.push_back({ plnt[i].num, plnt[i + 1].num, plnt[i + 1].x - plnt[i].x });
	}
	sort(plnt, plnt + N, compY);
	for (int i = 0; i < N - 1; i++) {
		ary.push_back({ plnt[i].num, plnt[i + 1].num, plnt[i + 1].y - plnt[i].y });
	}
	sort(plnt, plnt + N, compZ);
	for (int i = 0; i < N - 1; i++) {
		ary.push_back({ plnt[i].num, plnt[i + 1].num, plnt[i + 1].z - plnt[i].z });
	}
	sort(ary.begin(), ary.end(), comp);
	int ans = 0;
	for (int i = 0; i < ary.size(); i++) {
		if (find(ary[i].from) != find(ary[i].to)) {
			uni(ary[i].from, ary[i].to);
			ans += ary[i].cost;
		}
	}
	printf("%d\n", ans);
	return 0;
}