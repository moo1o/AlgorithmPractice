#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

enum {
	MAX =1,
	MIN
};
int k;
char oper[20];
vector<string> num;

int check[10];
bool complete = false;

bool cmp(char* a, char* b) {
	while (*a != '\0') {
		if (*a < *b)
			return true;
		a++;
		b++;
	}
	if (*b != '\0')
		return true;
	return false;
}

void cpy(char* dest, char* src) {
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest - '\0';
}

void dfs(int n, int op, string temp) {
	if (k + 1 == n) {
		num.push_back(temp);
		return;
	}
	if (n == 0) {
		for (int i = 0; i < 10; i++) {
			check[i] = 1;
			char c = '0' + i;
			string tmp = temp + c;
			dfs(n + 1, op, tmp);
			check[i] = 0;
		}
	}
	else {
		int st = 0, ed = 10;
		if (oper[op] == '<') {
			st = temp[n - 1] - '0' + 1;
			if (st > 9)
				return;
		}
		else if (oper[op] == '>') {
			ed = temp[n - 1] - '0';
			if (ed == 0)
				return;
		}
		for (int i = st; i < ed; i++) {
			if (check[i] == 0) {
				check[i] = 1;
				char c = '0' + i;
				string tmp = temp + c;
				dfs(n + 1, op + 1, tmp);
				check[i] = 0;
			}
		}
	}
}

int main(void) {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> oper[i];
	}
	
	dfs(0, 0, "");
	sort(num.begin(), num.end());

	cout << num[num.size() - 1] << endl << num[0] << endl;
		
	return 0;
}