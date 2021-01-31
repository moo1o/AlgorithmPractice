#include <iostream>
#include <cstdio>

using namespace std;

char map[6][6];
int slecMap[6][6];
pair<int, int> loc[30];
pair<int, int> slec[7];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

void check() {
	int cnt_S = 0;
	for (int i = 0; i < 7; i++) {
		int y = slec[i].first;
		int x = slec[i].second;
		if (map[y][x] == 'S') {
			cnt_S++;
		}
		int flag = false;
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if ((ny >= 0 && ny < 5 && nx >= 0 && nx <= 5) && slecMap[ny][nx] == 1) {
				flag = true;
				break;
			}
		}
		if (flag = false)
			return;
	}

	ans++;
}

void comb(int k, int cnt) {
	if (k == 26) {
		return;
	}
	if(cnt == 7){
		check();
		return;
	}
	comb(k + 1, cnt);
	slec[cnt] = loc[k];
	comb(k + 1, cnt+1);
}

int main(void) {
	int idx = 1;
	for (int i = 0; i < 5; i++) {
		scanf("%s", map[i]);
		for (int j = 0; j < 5; j++) {
			loc[idx] = make_pair(i, j);
			idx++;
		}
	}


	return 0;
}
