#include <cstdio>

struct MINSIK {
	int L;
	int O;
	int V;
	int E;
}OMS;

char oname[22];
char gname[55][22];
int N;
struct ANS {
	int cnt;
	char str[22];
}ans;

void _strcpy(char* dest, char* src) {
	while (*src != 0) *(dest++) = *(src++);
	*dest = 0;
}

bool _strcmp(const char* u, const char* v) {
	while (*u != 0) {
		if (*u < *v)
			return true;
		else if (*u > *v)
			return false;
		u++;
		v++;
	}
}

int main(void) {
	scanf("%s", oname);
	scanf("%d", &N);
	for (int i = 0; oname[i] != '\0'; i++) {
		if (oname[i] == 'L')
			OMS.L++;
		if (oname[i] == 'O')
			OMS.O++;
		if (oname[i] == 'V')
			OMS.V++;
		if (oname[i] == 'E')
			OMS.E++;
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", gname[i]);
		int L = OMS.L;
		int O = OMS.O; 
		int V = OMS.V;
		int E = OMS.E;
		for (int j = 0; gname[i][j] != '\0'; j++) {
			if (gname[i][j] == 'L')
				L++;
			if (gname[i][j] == 'O')
				O++;
			if (gname[i][j] == 'V')
				V++;
			if (gname[i][j] == 'E')
				E++;
		}
		//int tmp = ((L + O) % 100 * (L + V) % 100 * (L + E) % 100 * (O + V) % 100 * (O + E) % 100 * (V + E) % 100) % 100;
		int tmp = ((L + O)*(L + V)*(L + E)*(O + V)*(O + E)*(V + E)) % 100;
		if (tmp == ans.cnt) {
			if (ans.str[0] == 0 || !_strcmp(ans.str, gname[i])) {
				ans.cnt = tmp;
				_strcpy(ans.str, gname[i]);

			}
		}
		else if (tmp > ans.cnt) {
			ans.cnt = tmp;
			_strcpy(ans.str, gname[i]);
		}
	}

	printf("%s\n", ans.str);

	return 0;
}