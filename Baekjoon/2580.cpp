#include <iostream>
#include <vector>


using namespace std;

int map[10][10];
vector<pair<int, int>> pt;
bool flag = false; 




bool chkrow(int y, int x, int n) {
	for (int j = 0; j < 9; j++) {
		if (map[y][j] == n) {
			return false;
		}
	}
	return true;
}

bool chkcol(int y, int x, int n) {
	for (int i = 0; i < 9; i++) {
		if (map[i][x] == n) {
			return false; 
		}
	}
	return true;
}

bool chkbox(int y, int x, int n) {
	for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++) {
		for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++) {
			if (map[i][j] == n) {
				return false;
			}
		}
	}
	return true;
}

void func(int idx) {
	if (flag || idx == pt.size()) {
		flag = true;
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (chkrow(pt[idx].first, pt[idx].second, i) && chkcol(pt[idx].first, pt[idx].second, i) && chkbox(pt[idx].first, pt[idx].second, i)) {
			map[pt[idx].first][pt[idx].second] = i;
			func(idx + 1);
			if (flag)
				return;
			map[pt[idx].first][pt[idx].second] = 0;
		}
	}


}

int main(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				pt.push_back(make_pair(i, j));
			}
		}
	}

	func(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}