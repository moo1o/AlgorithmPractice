#include <cstdio>
#include <algorithm>
#define MAX 1005

using namespace std;

struct INFO {
	long long ab;
	int cls;
	int cnt;
};

INFO info[MAX*MAX];
int N, M;
int midx;
int check[MAX];
int _size;
long long ans;

bool comp(const INFO u, const INFO v) {
	return u.ab < v.ab;
}


int main(void) {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			scanf("%d", &tmp);
			info[midx].ab = tmp;
			info[midx++].cls = i;
			
		}
	}
	
	sort(info, info + midx, [](INFO u, INFO v) {
		return u.ab < v.ab;
	});
	/*for (int i = 0; i < midx; i++) {
		printf("%2d ", i);
	}
	printf("\n");
	for (int i = 0; i < midx; i++) {
	printf("%2d ", info[i].ab);
	}
	printf("\n");
	for (int i = 0; i < midx; i++) {
	printf("%2d ", info[i].cls);
	}
	printf("\n");
*/
	ans = info[midx - 1].ab;
	int L=0, R=0;
	check[info[L].cls]=1;
	_size++;
	
	while (true) {
		if (_size <N) {
			R++;
			if (R == midx)
				break;
			if (check[info[R].cls] == 0) {
				_size++;
			}
			check[info[R].cls]++;
			//printf("L:%d R:%d size:%d\n", L, R, _size);
		}
		if (_size == N) {
			if ((info[R].ab - info[L].ab) < ans)
				ans = info[R].ab - info[L].ab;
			check[info[L].cls]--;
			if(check[info[L].cls] == 0)
				_size--;
			L++;
			//printf("L:%d R:%d size:%d ans:%d\n", L, R, _size,ans);
		}
		
		
		if (R == midx)
			break;
	}

	printf("%lld\n", ans);
	
	return 0;
}