#include <cstdio>	
#include <math.h>
#define ll long long
using namespace std;

int T;
ll a, b;

void init() { a = 0, b = 0; }


ll func() {
	ll ret = 1;
	for (int i = 0; i < b; i++) {
		ret = (ret*a) % 10;
	}
	if (ret == 0)
		ret = 10;
	return ret;

}

int main(void) {
	scanf("%d", &T);
	
	while (T--) {
		init();
		scanf("%lld %lld", &a, &b);
		a = func();
		printf("%d\n", a);
	
	}
	

	return 0;
}