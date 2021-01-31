#include <iostream>
#include <vector>
#include <queue>
#define MAX 301
using namespace std;

int map[MAX][MAX];
int chkmap[MAX][MAX];
queue<pair<int, int>> pt;
queue<pair<int, int>> q;
int N, M;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int time;

bool is_inside(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

bool check() {
	//위치별로 크기 조정하면서 chkmap에 복사 
	for (int i = 0; i < pt.size(); i++) {
		int y = pt.front().first;
		int x = pt.front().second;
		if (map[y][x] == -1)
			map[y][x] = 0;
		chkmap[y][x] = map[y][x];
		if (map[y][x] == 0) {
			pt.pop();
			i--;
		}
		else {
			pt.push(pt.front());
			pt.pop();
		}
	}
	//chkmap에서 덩어리 표시
	
	q.push({ pt.front() });
	chkmap[pt.front().first][pt.front().second] = -1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (is_inside(ny,nx) &&chkmap[ny][nx] != -1) {
				if(chkmap[ny][nx] != 0)
					q.push({ ny, nx });
				chkmap[ny][nx] = -1;
			}
		}
	}

	
	pt.push(pt.front());
	pt.pop();
	for (int i = 1; i < pt.size(); i++) {
		if (chkmap[pt.front().first][pt.front().second] != 0 && chkmap[pt.front().first][pt.front().second] != -1)
			return false;
		pt.push(pt.front());
		pt.pop();
	}
	return true;

}

void func() {
	while (!pt.empty()) {
		for (int i = 0; i < pt.size(); i++) {
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (is_inside(pt.front().first + dy[j], pt.front().second + dx[j]) &&  map[pt.front().first + dy[j]][pt.front().second + dx[j]] == 0) {
					cnt++;
				}
			}
			if (map[pt.front().first][pt.front().second] > cnt) {
				map[pt.front().first][pt.front().second] -= cnt;
			}
			else {
				map[pt.front().first][pt.front().second] = -1;
			}
			cnt = 0;
			pt.push(pt.front());
			pt.pop();
		}
		time++;
		if (!check()) {
			return;
		}
	}
	time = 0; 
	return;
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				pt.push({ i, j });
			}
		}
	}

	func();

	cout << time << endl;

	return 0;
}