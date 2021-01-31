#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K;
int enrg[15][15];
int A[15][15];
struct INFO {
	int y, x, age;
	bool life;
};
vector<INFO> tree;
//queue<INFO> live;


bool comp(const INFO &a, const INFO &b) {
	if (a.age < b.age) {
		return true;
	}
	return false;
}

void spring() {
	sort(tree.begin(), tree.end(), comp);
	for (int i = 0; i < M; i++) {
		if (enrg[tree[i].y][tree[i].x] >= tree[i].age) {
			enrg[tree[i].y][tree[i].x] -= tree[i].age;
			tree[i].age++;
		}
		else {
			tree[i].life = false;
		}
	}
}

void summer() {
	for (int i = 0; i < M; i++) {
		if (tree[i].life == false) {
			enrg[tree[i].y][tree[i].x] += (tree[i].age / 2);
			//tree.erase(tree.begin() + i);
			tree[i] = tree[M - 1];
			tree.erase(tree.end()-1);
			i--;
			M--;

		}
	}
}


int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };

bool is_inside(int y, int x) {
	return y >= 1 && y <= N && x >= 1 && x <= N;
}

void fall() {
	int size = M;
	for (int i = 0; i < M; i++) {
		int y = tree[i].y;
		int x = tree[i].x;
		int age = tree[i].age;
		if (age % 5 == 0) {
			for (int j = 0; j < 8; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (is_inside(ny, nx)) {
					tree.push_back({ ny, nx, 1, true });
					size++;
				}
			}
		}
	}
	M = size;
}
void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			enrg[i][j] += A[i][j];
		}
	}
}

void solve() {
	for (int i = 0; i < K; i++) {
		spring();
		summer();
		fall();
		winter();
	}
}

int main(void) {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			enrg[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int y, x, age;
		scanf("%d%d%d", &y, &x, &age);
		tree.push_back({ y, x, age, true });
	}
	solve();
	printf("%d\n", M);

	return 0;
}