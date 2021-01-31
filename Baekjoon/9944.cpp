#include <iostream>
#define MAX 35
using namespace std;

int m, n, road;
char map[MAX][MAX];

void dfs(int )


int main(void) {
	ios::sync_with_stdio(false);
	while (true) {
		cin >> m >> n;
		road = 0;
		for (int i = 0; i < m; i++) {
			cin >> map[i];
			for (int j = 0; j < n; j++) {
				if (map[i][j] == '.')
					road++;
			}
		}
	}
	





	return 0;
}