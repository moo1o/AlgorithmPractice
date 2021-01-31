#include <iostream>
#include <cmath>
#define MAX 1005

using namespace std;

pair<int, int> st, ed;
pair<int, int> port[MAX];
int n, k;
double ans;

int _abs(int a) {
	return a > 0 ? a : -a;
}

void func(int m, pair<int, int> slec[MAX] ) {
	if (m == k + 1) {
		double tmp = 0;
		
		tmp = sqrt((double)(pow(slec[0].first - 0,2))+ (pow(slec[0].second - 0,2)));
		for (int i = 1; i < m-1; i++) {
			tmp += sqrt((double)(pow(slec[i].first - slec[i-1].first,2)) + (pow(slec[i].second - slec[i].second,2)));
		}
		tmp += sqrt((double)(pow(slec[m-1].first - 10000,2)) + (pow(slec[m-1].second - 10000,2)));
		if (tmp < ans) {
			ans = tmp;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		slec[m].first = port[i].first;
		slec[m].second = port[i].second;
		func(m + 1, slec);
	}
}


int main(void) {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> port[i].first >> port[i].second;
	}
	pair<int, int> slec[MAX];
	ans = 987654321;
	func(0, slec);

	cout << ans << endl;

	return 0;
}