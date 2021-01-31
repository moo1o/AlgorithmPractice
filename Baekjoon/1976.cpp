#include <iostream>
#define MAX 205
using namespace std;

int N, M;
int p[MAX];

int find(int x) {
	if (x == p[x]) return x;
	else
		return find(p[x]);
}

void uni(int y, int x) {
	y = find(y);
	x = find(x);
	p[y] = x;
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		p[i] = i;
	}
	int in;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> in;
			if (in)
				uni(i, j);
		}
	}
	
	int st; 
	cin >> st;
	st = find(st);
	for (int i = 0; i < M - 1; i++) {
		cin >> in;
		if (st != find(in)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}