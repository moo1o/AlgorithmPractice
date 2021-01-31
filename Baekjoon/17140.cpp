#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 120
using namespace std;

struct info {
	int num, cnt;
};
int r, c, k, ans;
int row = 3, col = 3;
int map[MAX][MAX];


bool comp(info a, info b) {
	if (a.cnt < b.cnt) {
		return true;
	}
	else if (a.cnt == b.cnt && a.num < b.num) {
		return true;
	}
	return false;
}


void calcR(int i) {
	int cnt_ary[101] = { 0 };
	int max = 0; 
	for (int j = 0; j < col; j++) {
		cnt_ary[map[i][j]]++;
		if (map[i][j] > max)
			max = map[i][j];
		map[i][j] = 0;
	}
	vector<info> v; 
	for (int j = 1; j <= max; j++) {
		if (cnt_ary[j]) {
			v.push_back({ j, cnt_ary[j] });
		}
	}
	sort(v.begin(), v.end(), comp);
	if (v.size()*2 > col)
		col = v.size()*2;
	int idx = 0;
	for (int j = 0; j < v.size(); j++) {
		map[i][idx] = v[j].num;
		map[i][idx + 1] = v[j].cnt;
		idx += 2;
	}
}

void calcC(int j) {
	int cnt_ary[101] = { 0 };
	int max = 0;
	for (int i = 0; i < row; i++) {
		cnt_ary[map[i][j]]++;
		if (map[i][j] > max)
			max = map[i][j];
		map[i][j] = 0;
	}
	vector<info> v;
	for (int i = 1; i <= max; i++) {
		if (cnt_ary[i]) {
			v.push_back({ i, cnt_ary[i] });
		}
	}
	sort(v.begin(), v.end(), comp);
	if (v.size()*2 > row)
		row = v.size()*2;
	int idx = 0; 
	for (int i = 0; i < v.size(); i++) {
		map[idx][j] = v[i].num;
		map[idx+1][j] = v[i].cnt;
		idx += 2;
	}
}

void func() {
	for (int T = 1; T <= 100; T++) {
		if (row >= col) {
			for (int i = 0; i < row; i++) {
				calcR(i);
			}
		}
		else {
			for (int j = 0; j < col; j++) {
				calcC(j);
			}
		}
		if (map[r][c] == k) {
			ans = T;
			return;
		}
	}
	ans = -1;
	return;
}




int main(void) {
	cin >> r >> c >> k;
	r--;
	c--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	if(map[r][c] != k)
		func();
	cout << ans << endl;


	return 0;
}