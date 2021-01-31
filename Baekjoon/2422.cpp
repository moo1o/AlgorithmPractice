#include <iostream>
#include <vector>
#define MAX 300
using namespace std;

int N, M;
int cant[MAX][MAX];
int check[MAX];
int ans;

void comb(int k, vector<int> arr, int n) {
	
	if (n == 3) {
		if (cant[arr[0]][arr[1]] != 1 &&
			cant[arr[0]][arr[2]] != 1 &&
			cant[arr[1]][arr[2]] != 1) {
			ans++;
		}
		return;
	}
	if (k == N + 1 || (n == 2 &&
		cant[arr[0]][arr[1]] == 1)) {
		return;
	}
	comb(k+1, arr, n);
	arr.push_back(k);
	comb(k + 1, arr, n+1);
	arr.pop_back();
}


int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int in1, in2;
		cin >> in1 >> in2; 
		cant[in1][in2] = 1;
		cant[in2][in1] = 1;
	}
	vector<int> arr;
	comb(1, arr, 0);

	cout << ans << endl;

	return 0;
}