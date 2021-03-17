//N°úM(4)

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> check;

void func(int N, int M, int k, int l, vector<int> v) {
	if (l == M) {
		if (check.find(v)== check.end()) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << endl;
			check.insert(v);
		}
		
	}
	else if (k > N || l > M) {
		return;
	}
	else {
		v.push_back(k);
		func(N, M, k, l + 1, v);
		v.pop_back();
		if (k + 1 <= N) {
			v.push_back(k + 1);
			func(N, M, k + 1, l + 1, v);
			v.pop_back();
			func(N, M, k + 1, l, v);
		}
		
	}
}


void solution(int N, int M) {
	for (int i = 1; i < N + 1; i++) {
		vector<int> v = { i };
		func(N, M, i, 1, v);
	}
}

int main(void) {
	int N;
	int M;
	cin >> N >> M;

	solution(N, M);
		

	return 0;
}