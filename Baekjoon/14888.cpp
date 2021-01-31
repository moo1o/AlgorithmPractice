#include <iostream>
#define MAX 105
#define ll long long
using namespace std;

enum {
	ADD,
	SUB,
	MUL,
	DIV	
};
int oper[4];
int N;
ll _max = -1000000000, _min = 1000000000;
ll A[MAX];

ll _abs(ll a) {
	return a > 0 ? a : -a;
}

void dfs(int k, int op[4], ll ret) {
	if (k == N) {
		if (ret > _max)
			_max = ret;
		if (ret < _min)
			_min = ret;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			switch (i) {
			case ADD:
				op[i]--;
				dfs(k + 1, op, ret + A[k]);
				op[i]++;
				break;
			case SUB:
				op[i]--;
				dfs(k + 1, op, ret - A[k]);
				op[i]++;
				break;
			case MUL:
				op[i]--;
				dfs(k + 1, op, ret * A[k]);
				op[i]++;
				break;
			case DIV:
				op[i]--;
				ll tmp = _abs(ret) / _abs(A[k]);
				if (ret < 0 || A[k] < 0)
					tmp = -tmp;
				dfs(k + 1, op, tmp);
				op[i]++;
				break;
			}
		}
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}
	dfs(1, oper, A[0]);
	printf("%lld\n%lld\n", _max, _min);

	return 0;
}

