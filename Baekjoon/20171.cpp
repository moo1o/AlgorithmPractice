#include <iostream>
#include <string>
#define MAX 100

using namespace std;
string N;
int ary[MAX];
int check[MAX];
int cnt;

void init() {
	N = "";
	memset(ary, 0, sizeof(ary));
	memset(check, 0, sizeof(ary));
	cnt = 0;
}

int _abs(int target) {
	return target > 0 ? target : -target;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (true) {
		init();
		cin >> N;
		int n;
		if (N[0] == 'q') {
			break;
		}
		else {
			n = stoi(N);
			cnt = n - 1; 
		}
		for (int i = 0; i < n; i++) {
			cin >> ary[i];
			if (i > 0) {
				int tmp = _abs(ary[i - 1] - ary[i]);
				if (check[tmp] == 0) {
					cnt--;
				}
				check[tmp]++;
			}
		}
		if (cnt == 0) {
			cout << "성립합니다." << endl;
		}
		else {
			cout << "성립하지 않습니다." << endl;
		}
	}

	return 0;
}