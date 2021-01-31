#include <iostream>
#include <queue>
using namespace std;

struct INFO {
	int y, x, d, size;
};
int N, M;
int ans = 987654321;
int map[105][105];
int visit[5][105][105];
int ch[105][105];
INFO st, ed;
int dy[] = { 0, 0, 0, 1, -1 };
int dx[] = { 0, 1, -1, 0, 0 };
/*
	동 1 서 2 남 3 북 4
	오른쪽 : 동 -> 남 -> 서 -> 북
	왼쪽 : 동 -> 북 -> 서 -> 남

*/

bool is_inside(int y, int x) {
	return y >= 1 && y <= M && x >= 1 && x <= N;
}

void func() {
	queue<INFO> q;
	q.push(st);
	visit[q.front().d][q.front().y][q.front().x] = 1;
	ch[q.front().y][q.front().x] = 1;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int d = q.front().d;
		int size = q.front().size;
		if (y == ed.y && x == ed.x && d == ed.d) {
			ans = size;
			return;
		}
		
		q.pop();

		for (int i = 1; i <= 5; i++) {
			int ny, nx, nd, nsize;
			switch (i) {
			case 1: // 현재 방향에서 1칸 이동
			case 2: // 현재 방향에서 2칸 이동
			case 3: // 현재 방향에서 3칸 이동
				ny = y + (dy[d]*i);
				nx = x + (dx[d]*i);
				nd = d;
				nsize = size+1;
				
				if (is_inside(ny, nx) && visit[nd][ny][nx] == 0 && map[ny][nx] == 0) {
					visit[nd][ny][nx] = 1;
					ch[ny][nx] = 1;
					q.push({ ny, nx, nd, nsize });
					
				}
				if (map[ny][nx] == 1) {
					i = 3;
				}
				break;
			case 4: // 현재 방향에서 왼쪽 회전
				ny = y;
				nx = x;
				switch (d) {
				case 1: // 동 -> 북
					nd = 4;
					break;
				case 2: // 서 -> 남
					nd = 3;
					break;
				case 3: // 남 -> 동
					nd = 1;
					break;
				case 4: // 북 -> 서
					nd = 2;
					break;
				}
				nsize = size + 1;
				if (visit[nd][ny][nx] == 0) {
					visit[nd][ny][nx] = 1;
					q.push({ ny, nx, nd, nsize });
				}
				break; 
			case 5: // 현재 방향에서 오른쪽 회전
				ny = y;
				nx = x;
				switch (d) {
				case 1: // 동 -> 남
					nd = 3;
					break;
				case 2: // 서 -> 북
					nd = 4;
					break;
				case 3: // 남 -> 서
					nd = 2;
					break;
				case 4: // 북 -> 동
					nd = 1;
					break;
				}
				nsize = size + 1;
				if (visit[nd][ny][nx] == 0) {
					visit[nd][ny][nx] = 1;
					q.push({ ny, nx, nd, nsize });
				}
				break;
			}
			//if (ny == ed.y && nx == ed.x && nd == ed.d && ans > nsize) {
			
		}
	}



}


int main(void) {
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> st.y >> st.x >> st.d;
	cin >> ed.y >> ed.x >> ed.d;
	func();
	cout << ans << endl;
	return 0;
}