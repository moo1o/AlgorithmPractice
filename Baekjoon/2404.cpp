#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <memory.h>
using namespace std;

double p, q, a, n;
set<vector<int>> chk;
int cnt;

void cpy(vector<int> &temp, vector<int> &ary) {
	for (int i = 0; i < ary.size(); i++) {
		temp.push_back(ary[i]);
	}
}

void func(int k, double ret, int mul, vector<int> ary) {
	if (k <= n) {
		if (ret == p / q && mul <= a) {
			vector<int> temp;
			cpy(temp, ary);
			sort(temp.begin(), temp.end());
			if (!chk.count(temp)) {
				chk.insert(temp);
				cnt++;
			}
			return;
		}
		if (k == n || ret > p/q || mul > a)
			return;
	}

	for (int i = 2; i < a / 2; i++) {
		ary.push_back(i);
		func(k + 1, ret + (1.0 / i), mul*i, ary);
		ary.pop_back();
	}
}


int main(void) {
	cin >> p >> q >> a >> n;
	vector<int> ary;
	func(0, 0.0, 1, ary);
	cout << cnt << endl;

	return 0;
}