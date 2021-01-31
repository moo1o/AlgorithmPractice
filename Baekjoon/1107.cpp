#include <cstdio>

int N, M, ans;
int btn[10];

int _abs(int x) {
	return x > 0 ? x : -x;
}

int check(int n) {
	if (n == 0) {
		if (btn[0])
			return -1;
		else
			return 1;
	}
	int cnt = 0;
	while (n > 0) {
		int x = n % 10;
		if (btn[x] == 1)
			return -1;
		n /= 10;
		cnt++;
	} 
	return cnt;
}

void func(int N) {
	int cnt = check(N);
	if (cnt != -1) {
		if (ans > cnt)
			ans = cnt;
	}
	else {
		/*int i = 1;
		int t1 = -1;
		int t2 = -1;
		for (; t1 == -1 && t2 == -1; i++) {
			if((N - i)>=0)
				t1 = check(N - i);
			if((N+i)<=1000000)
				t2 = check(N + i);
			if (t1 > ans && t2 > ans)
				return;
		}
		if (t1 != -1) {
			t1 += (i - 1);
			cnt = t1;
		}
		if (t2 != -1) {
			t2 += (i - 1);
			cnt = t2;
		}
		
		if (ans > cnt)
			ans = cnt;
		*/

		for (int i = 0; i <= 1000000; i++) {
			int c = i;
			int len = check(c);
			if (len > 0) {
				int press = _abs(c - N);
				if (ans > len + press) {
					ans = len + press;
				}
			}
		}
	}
	
}

int main(void) {
	scanf("%d%d", &N, &M);
	
	for (int i = 0; i < M; i++) {
		int in;
		scanf("%d", &in);
		btn[in] = 1;
	}

	ans = _abs(N - 100);
	if(ans != 0)
		func(N);
	printf("%d\n", ans);
	return 0;
}