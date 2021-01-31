#include <iostream>
#include <vector>
#include <set>
#define MAX 10
using namespace std;

int N, M;
int ary[MAX];
vector<int> ans;
int check[MAX];
int ch_num[10001];
set<vector<int>> ans_ary;

void perm(int c) {
	if (c == M) {
		ans_ary.insert(ans);
		return;
	}
	for (int i = 0; i < N; i++) {
		//if (check[i] == 0 && ch_num[ary[i]] == 0) {
		if (check[i] == 0) {
			check[i] = 1;
			ch_num[ary[i]] = 1;
			ans.push_back(ary[i]);
			perm(c + 1);
			ans.erase(ans.end()-1);
			ch_num[ary[i]] = 0;
			check[i] = 0;
		}
	}
}


int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}
	perm(0);

	set<vector<int>>::iterator iter;
	for (iter = ans_ary.begin(); iter != ans_ary.end(); iter++) {
		for (int i = 0; i < M; i++) {
			cout << (*iter)[i] << " ";
		}
		cout << endl;
	}

	return 0;
}