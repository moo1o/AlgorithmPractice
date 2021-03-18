//N°ú M(10)
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int N, M;
vector<int> num;
set<vector<int>> chk;
void func(int n, vector<int> ans) {
	if (ans.size() == M) {
		for (int i = 0; i < M - 1; i++) {
			if (ans[i] > ans[i + 1]) {
				return;
			}
		}
		if (chk.find(ans) == chk.end()) {
			chk.insert(ans);
			for (int i = 0; i < M; i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
		

		return;
	}
	for (int i = n; i < N; i++) {
		ans.push_back(num[i]);
		func(i+1, ans);
		ans.pop_back();
	}
}


int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		num.push_back(input);
		sort(num.begin(), num.end());
	}
	vector<int> ans;

	func(0, ans);

	return 0;
}