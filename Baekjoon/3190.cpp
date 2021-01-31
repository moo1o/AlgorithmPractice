#include <iostream>	
#define MAX 105
using namespace std;


int N, K, L, ans;
int input[MAX][MAX];
char dir[10005];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };



bool is_outside(int y, int x) {
	return y <= 0 || y > N || x <= 0 || x > N;
}



void dir_check(int& d, const int t) {
	if (dir[t] == 'D') {
		d++;
		if (d == 4)
			d = 0;


	}
	if (dir[t] == 'L') {
		d--;
		if (d == -1)
			d = 3;
	}
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//cout << input[i][j] << " ";
			printf("%2d", input[i][j]);
		}
		//cout << endl;
		printf("\n");
	}
	//cout << endl;
	printf("\n");
}

void solve(int d, int t, int hy, int hx, int ty, int tx) {
	cout << "t = " << t << endl;
	print();
	dir_check(d, t);
	int ny = hy + dy[d];
	int nx = hx + dx[d];

	if (is_outside(ny, nx) || input[ny][nx] >1) {
		if (input[ny][nx] != input[ty][tx]) {
			ans = t + 1;
			return;
		}
	}
	else {
		if (input[ny][nx] == 1) {
			input[ny][nx] = input[hy][hx] +1;
			solve(d, t + 1, ny, nx, ty, tx);
		}
		else if ((input[ny][nx] == 0) || (input[ny][nx] == input[ty][tx])) {
			for (int i = 0; i < 4; i++) {
				int nty = ty + dy[i];
				int ntx = tx + dx[i];
				if (!is_outside(nty, ntx) && input[nty][ntx] == input[ty][tx] +1) {
					input[ty][tx] = 0;
					solve(d, t + 1, ny, nx, nty, ntx);
					if (ans != 0)
						return;
				}
			}
			input[ny][nx] = input[hy][hx] + 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		input[y][x] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int x;
		char c;
		cin >> x >> c;
		dir[x] = c;
	}
	input[1][1] = 2;
	solve(0, 0, 1, 1, 1, 1);

	cout << ans<< endl;

	return 0;
}