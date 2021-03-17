//N°ú M(5)

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> num;

void func(vector<int> ans, vector<int> chk) {
	if (ans.size() == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		if (chk[i] == 0) {
			ans.push_back(num[i]);
			chk[i] = 1;
			func(ans, chk);
			ans.pop_back();
			chk[i] = 0;
			
		}
	}
}


int main(void) {
	scanf("%d %d", &N, &M);
	vector<int> chk;
	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		num.push_back(input);
		sort(num.begin(), num.end());
		chk.push_back(0);
	}
	vector<int> ans;
	
	func(ans, chk);
	
	return 0;
}