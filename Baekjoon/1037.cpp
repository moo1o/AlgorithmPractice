#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;
vector<int> sub;

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int in;
		scanf("%d", &in);
		sub.push_back(in);
	}

	sort(sub.begin(), sub.end());
	int size = sub.size();
	if (size % 2 == 0) {
		ans = sub[0] * sub[size - 1];
	}
	else {
		ans = sub[size/2]* sub[size / 2];
	}

	printf("%d\n", ans);

	return 0;
}