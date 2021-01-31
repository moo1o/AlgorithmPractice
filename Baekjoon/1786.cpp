#include <cstdio>
#include <string>
using namespace std;

char T[1000005];
char P[1000005];
int hT[1000005];
int hP;
int n, m;
int cnt, loc[10000005];

int _strlen(char* dest) {
	int len = 0;
	while (*dest != '\0') {
		dest++;
		len++;
	}
	return len;
}


int main(void) {
	scanf("%[^\n]", T);
	scanf("%s", P);
	scanf("%[^\n]", P);
	n = _strlen(T);
	m = _strlen(P);
	
	int mul = 1;
	for (int i = 0; i <m; i++) {
		hP += ((int)(P[i]) * mul);
		hT[0] += ((int)(T[i]) * mul);
		mul *= 2;
		hP %= 1000000;
	}
	if (hT[0] == hP) {
		loc[cnt] = 1;
		cnt++;
	}

	mul /= 2;
	for (int i = 1; i < n-m; i++) {
		hT[i] -= (int)(T[i-1]+ 1);
		hT[i] /= 2;
		hT[i] += (int)(T[i - 1] + 1) * mul;
		
		if (hT[i] == hP) {
			loc[cnt] = i+1;
			cnt++;
		}
	}

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", loc[i]);
	}

	return 0;
}