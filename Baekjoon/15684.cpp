#include <iostream>


using namespace std;
int N, M, H;
int ladder[50][15];
int ans = -1;

bool check() {
	for (int j = 1; j <= N; j++) {
		int cur_y = j;
		for (int i = 1; i <= H; i++) {
			if (ladder[i][cur_y] == 1) {
				cur_y += 1;
			}
			else if (cur_y - 1 > 0 && ladder[i][cur_y - 1] == 1) {
				cur_y -= 1;
			}
		}
		if (cur_y != j) {
			return false;
		}
	}
	return true;
}

void func(int row, int cnt, int max_L) {
	if (ans != -1) return;
	if (cnt == max_L) {
		if (check()) {
			ans = cnt;
		}
		return;
	}
	for (int i = row; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (!ladder[i][j]) {
				if (ladder[i][j - 1] == 0 && ladder[i][j + 1] == 0) {
					ladder[i][j] = 1; 
					func(i, cnt + 1, max_L);
					ladder[i][j] = 0;
				}
			}
		}
	}


}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int y, x; 
		cin >> y >> x;
		ladder[y][x] = 1;
	}
	
	for (int i = 0; i < 4; i++) {
		func(1, 0, i);
		if (ans != -1)
			break;
	}
	
		
	cout << ans << endl;
	
	return 0;
}