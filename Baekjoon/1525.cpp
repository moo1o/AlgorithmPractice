#include <iostream>
#include <queue>
#include <set>
#define mp make_pair
#define ll long long
using namespace std;

ll input[4][4];
pair<int, int> st;
set<ll> ch;
ll perfect = 87654321;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int ans; 

void swap(ll& a, ll& b) {
	ll t = a;
	a = b; 
	b = t;
}

bool is_inside(int y, int x) {
	return x >= 0 && x < 3 && y >= 0 && y < 3;
}

ll changelong(ll map[3][3]) {
	ll k = 1;
	ll t = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			t += map[i][j] * k;
			k *= 10;
		}
	}
	return t;
}

void changemap(ll in, ll map[3][3]) {
	ll k = 100000000;
	
	for (int i = 2; i >= 0; i--) {
		for (int j = 2; j >=0; j--) {
			map[i][j] = in / k;
			in %= k;
			k /= 10;	
		}
	}
}

int main(void) {
	ll k = 1;
	ll t = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%lld", &input[i][j]);
			t += input[i][j] * k;
			k *= 10;
			if (input[i][j] == 0)
				st = mp(i, j);
		}
	}
	if (t != perfect) {
		ch.insert(t);
		queue <pair<pair<ll,int>, pair<int,int>>> q;
		q.push(mp(mp(t, 0), st));

		while (!q.empty() && ans ==0) {
			int y = q.front().second.first;
			int x = q.front().second.second;
			ll in = q.front().first.first;
			int cnt = q.front().first.second;
			ll map[3][3];
			changemap(in, map);
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (is_inside(ny, nx)) {
					swap(map[ny][nx], map[y][x]);
					ll tmp = changelong(map);
					if (ch.end() == ch.find(tmp)) {
						if (tmp == perfect) {
							ans = cnt + 1;
							break;
						}
						ch.insert(tmp);
						q.push(mp(mp(tmp, cnt + 1), mp(ny, nx)));
					}
					swap(map[ny][nx], map[y][x]);
				}
			}

		}
		if (ans == 0)
			ans = -1;
	}
	

	printf("%d\n", ans);
	
	return 0;
}