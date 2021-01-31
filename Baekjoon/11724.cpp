#include <iostream>
#include <set>
#define MAX 1005

using namespace std;

int N, M;
int ary[MAX];
struct EDGE {
	int from, to;
}E[MAX*MAX];
set<int> s;

int find(int x) {
	if (x == ary[x])
		return ary[x];
	else
		return ary[x] = find(ary[x]);
}

void uni(int y, int x) {
	y = find(y);
	x = find(x);
	ary[y] = x;
}


int main(void) {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		ary[i] = i;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &E[i].from, &E[i].to);
		uni(E[i].from, E[i].to);
	}
	for (int i = 1; i <= N; i++) {
		find(i);
	}
	s.insert(ary[1]);
	int cnt = 1;
	for (int i = 2; i <= N; i++) {
		if (s.end() == s.find(ary[i])) {
			s.insert(ary[i]);
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}