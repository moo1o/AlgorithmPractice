#include <iostream>
#define MAX 1000001
using namespace std;

int N, M, K;
long long ary[MAX];
long long tree[MAX];


long long init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = ary[start];
	}
	else {
		return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

void update(int node, int index, int diff, int start, int end) {
	if (index < start || index > end)
		return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(node * 2, index, diff, start, (start + end) / 2);
		update(node * 2 + 1, index, diff, (start + end) / 2 + 1, end);
	}
}

long long sum(int node, int start, int end, int left, int right) {
	if (start > right || end < left) {
		return 0;
	}
	if (start >= left && end <= right) {
		return tree[node];
	}
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void) {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}
	init(1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1LL) {
			int diff = c - ary[b-1];
			ary[b-1] = c;
			update(1, b-1, diff, 0, N-1);
		}
		else {
			cout << sum(1, 0, N - 1, b - 1, c - 1) << endl;
		}
	}


	return 0;

}