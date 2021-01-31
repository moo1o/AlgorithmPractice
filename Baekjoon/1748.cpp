#include <iostream>


using namespace std;

int N;
int d = 10;
int cnt = 1;
int ans = 1;
long long tmp = 1;

int main(void) {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (i%d == i) {
			ans += cnt;
		}
		else {
			d *= 10;
			cnt++;
			ans += cnt;
		}
		tmp *= d;
		tmp += i;
	}
	cout << ans << endl;;


	return 0;
}