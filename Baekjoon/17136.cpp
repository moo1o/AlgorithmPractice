#include <iostream>

using namespace std;

int paper_cnt[6];
int ans = -1;

bool is_inside(int y, int x) {
	return y >= 0 && y < 10 && x >= 0 && x < 10;
}

bool check(int size, int y, int x , int map[10][10]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (!is_inside(y+i, x+j) || map[y + i][x + j] == 0) {
				return false;
			}
		}
	}
	return true;
}

void func(int y, int x, int cnt, int ret, int map[10][10]) {
	if (ans != -1 && ret > ans)
		return;
	if (cnt == 0) {
		if(ans == -1 || ans > ret)
				ans = ret;
		return;
	}
	int sum = 0;
	for (int i = 1; i < 6; i++) {
		sum += paper_cnt[i];
	}
	if (sum == 0) {
		return;
	}
	bool flag = false;
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (map[i][j] == 1) {
				flag = true;
				break;
			}
			
		}
		if (flag)
			break;
	}

	for (int num = 5; num > 0; num--) {
		if (paper_cnt[num] > 0 && check(num, i, j, map)) {
			for (int k = 0; k < num; k++) {
				for (int l = 0; l < num; l++) {
					map[i + k][j + l] = 0;
				}
			}
			cnt -= (num * num);
			paper_cnt[num]--;
			ret++;
			func(i, j, cnt, ret, map);
			for (int k = 0; k < num; k++) {
				for (int l = 0; l < num; l++) {
					map[i + k][j + l] = 1;
				}
			}
			cnt += (num * num);
			paper_cnt[num]++;
			ret--;
		}
	}
}

int main(void) {
	for (int i = 1; i < 6; i++) {
		paper_cnt[i] = 5;
	}
	int cnt = 0;
	int map[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				cnt++;
		}
	}
	func(0, 0, cnt, 0, map);

	cout << ans << endl;

	return 0;
}