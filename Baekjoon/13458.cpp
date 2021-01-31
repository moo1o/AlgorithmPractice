#include <cstdio>
#define MAX 1000005
#define ll long long
using namespace std;

ll N, B, C;
ll A[MAX];

int main(void){
	scanf("%lld", &N);
	//N = 1000000;
	for (ll i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		//A[i] = N;
	}
	scanf("%lld%lld", &B, &C);
	//B = C = 1LL;
	ll cnt = 0;
	for (ll i = 1; i <= N; i++) {
		ll tmp = A[i];
		tmp -= B;
		cnt++;
		if (tmp > 0) {
			if (tmp%C == 0) {
				cnt += tmp / C;
			}
			else {
				cnt += tmp / C + 1;
			}
		}
		
	}

	printf("%lld\n", cnt);
	return 0;
}