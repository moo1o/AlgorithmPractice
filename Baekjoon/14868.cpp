#include <cstdio>
#include <queue>
#include <memory.h>
#define MAX 2005
#define MAXK 100005
using namespace std;

int N, K;
int map[MAX][MAX];
struct INFO {
	int y, x;
}loc[MAXK];
int P[MAX*MAX];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int visit[MAX][MAX];
int num[MAX][MAX];
int cnt;

int find(int n) {
	if (P[n] == n) {
		return n;
	}
	else
		return P[n] = find(P[n]);
}

void uni(int n, int m) {
	n = find(n);
	m = find(m);

	P[m] = n;
}

bool is_inside(int y, int x) {
	return y > 0 && y <= N && x > 0 && x <= N;
}

//void group() {
//	cnt = K;
//	for (int i = 1; i <= K; i++) {
//		if (P[i] != i)
//			continue;
//		queue<INFO> q;
//		q.push(loc[i]);
//		visit[loc[i].y][loc[i].x] = 1;
//		while (!q.empty()) {
//			int y = q.front().y;
//			int x = q.front().x;
//			q.pop();
//			for (int k = 0; k < 4; k++) {
//				int ny = y + dy[k];
//				int nx = x + dx[k];
//				if (is_inside(ny, nx) && map[ny][nx] == 1 && visit[ny][nx] == 0) {
//					visit[ny][nx] = 1;
//					uni(i, num[ny][nx]);
//					q.push({ ny, nx });
//					cnt--;
//				}
//			}
//		}
//	}
//	
//}

int bfs() {
	//전체문명이 하나면 리턴
	if (cnt == 1)
		return 0;
	queue<INFO> q; 
	for (int i = 1; i <= K; i++) {
		q.push(loc[i]);
	}
	int day = 1;
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int y = q.front().y;
			int x = q.front().x;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (is_inside(ny, nx)) {
					//아무도 점령하지 않은 곳
					if (visit[ny][nx] == 0) {
						visit[ny][nx] = 1;
						uni(num[y][x], num[ny][nx]);
						q.push({ ny, nx });
						for (int k = 0; k < 4; k++) {
							int nny = ny + dy[k];
							int nnx = nx + dx[k];
							if (is_inside(nny, nnx) && visit[nny][nnx] == 1 && find(num[ny][nx]) != find(num[nny][nnx])) {
								uni(num[ny][nx], num[nny][nnx]);
								cnt--;
							}
						}
					}
					//내땅이거나 남의 땅
					else if (visit[ny][nx] == 1 && find(num[y][x]) != find(num[ny][nx])) {
						uni(num[y][x], num[ny][nx]);
						cnt--;
					}
				}
				if (cnt == 1) {
					return day;
				}
			}
		}
		day++;
	}
}

void init() {
	int t = K + 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (num[i][j] == 0) {
				P[t] = t;
				num[i][j] = t++;
			}
		}
	}
}

int main(void) {
	scanf("%d%d", &N, &K);
	cnt = K;
	for (int i = 1; i <= K; i++) {
		scanf("%d%d", &loc[i].y, &loc[i].x);
		map[loc[i].y][loc[i].x] = 1;
		P[i] = i;
		num[loc[i].y][loc[i].x] = i;
		visit[loc[i].y][loc[i].x] = 1;
		for (int j = 0; j < 4; j++) {
			int ny = loc[i].y + dy[j];
			int nx = loc[i].x + dx[j];
			if (is_inside(ny, nx) && map[ny][nx] == 1 && find(i) != find(num[ny][nx])) {
				uni(i, num[ny][nx]);
				cnt--;
			}

		}
	}
	init();
	//group();
	int day = bfs();

	printf("%d\n", day);
	


	return 0;
}