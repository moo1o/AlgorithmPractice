#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N, K;
vector<pair<int, int>> things;
int dp[100003][103] = {0};
int ans=-1;

void solutions(int idx, int w, int v) {
	
	
}

int main(void) {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int w, v; 
		cin >> w >> v;
		things.push_back(make_pair(w, v));
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			int w = things[j - 1].first;
			int v = things[j - 1].second;
			if (things[j - 1].first <= i) {
				dp[i][j] = max(dp[i][j - 1], v+dp[i - w][j - 1]);
			}
			else
				dp[i][j] = dp[i][j - 1];
			ans = max(ans, dp[i][j]);
		}
	}


	cout << ans << endl;




	return 0;
}