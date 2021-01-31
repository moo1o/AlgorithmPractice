#include <iostream>	
#define MAX 100
using namespace std;

int N;
int pD[4];
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int visit[MAX][MAX];
double ans;
void dfs(int n, int y, int x, double total) {
	
	if (n == N) {
		ans += total;
		return;
	}
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (visit[ny][nx] == 0) {
			visit[ny][nx] = 1;
			dfs(n + 1, ny, nx, total*pD[i] / 100);
			visit[ny][nx] = 0;
		}
	}
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> pD[i];
	}
	//visit[50][50] = 1;
	dfs(0, 50, 50, 1.0);
	ans = 0.123456781234;
	cout.precision(10);
	cout << ans << endl;
	//printf("%.10lf", ans);
	
	return 0;
}