#include <iostream>
#define MAX 20
using namespace std;

int N, ans;
struct INFO {
	int T;
	int P;
}info[MAX];

void func(int day, int ary[MAX]) {
	/*for (int i = 1; i <= N; i++) {
		printf("%3d", ary[i]);
	}
	printf("\n");*/
	if (day == N+1) {
		if (ary[N] > ans)
			ans = ary[N];
		return;
	}

	//if (ary[day] == 0) {
		int i;
		int tmp[MAX] = { 0 };
		for (i = day; i<=N && i < day+info[day].T; i++) {
			if(day + info[day].T - 1 <= N)
				tmp[i] = ary[day - 1] + info[day].P;
			else {
				tmp[i] = ary[day - 1];
			}
		}
		func(i, tmp);
		ary[day] = ary[day-1];
		func(day+1, ary);
	//}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &info[i].T, &info[i].P);
	}
	int ary[MAX] = { 0 };
	func(1, ary);

	printf("%d\n", ans);

	return 0;
}