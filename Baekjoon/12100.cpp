#include <cstdio>
#define MAX 22
int N, ans;
int map[MAX][MAX];

enum {
	first,
	up,
	down,
	left,
	right
};

void func(int cnt, int _map[MAX][MAX], int type) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (_map[i][j] > ans) {
					ans = _map[i][j];					
				
					/*for (int k = 0; k < N; k++) {
						for (int l = 0; l < N; l++) {
							printf("%2d", _map[k][l]);
						}
						printf("\n");
					}
					printf("\n");*/
				}

			}
		}
		return;
	}
		
	//À§
	if (type != up) {
		int tmp[MAX][MAX] = { 0 };
		for (int j = 0; j < N; j++) {
			int index = 0;
			for (int i = 0; i < N; i++) {
				if (_map[i][j] != 0) {
					if (tmp[index][j] == 0) {
						tmp[index][j] = _map[i][j];
					}
					else if (tmp[index][j] == _map[i][j]) {
						tmp[index][j] += _map[i][j];
						index++;
					}
					else if (tmp[index][j] != _map[i][j]) {
						tmp[++index][j] = _map[i][j];
					}
				}
			}
		}
		/*for (int k = 0; k < N; k++) {
			for (int l = 0; l < N; l++) {
				printf("%2d", tmp[k][l]);
			}
			printf("\n");
		}
		printf("\n");*/
		func(cnt + 1, tmp, up);
	}
	
	//¾Æ·¡
	if (type != down) {
		int tmp[MAX][MAX] = { 0 };
		for (int j = 0; j < N; j++) {
			int index = N-1;
			for (int i = N-1; i >= 0; i--) {
				if (_map[i][j] != 0) {
					if (tmp[index][j] == 0) {
						tmp[index][j] = _map[i][j];
					}
					else if (tmp[index][j] == _map[i][j]) {
						tmp[index][j] += _map[i][j];
						index--;
					}
					else if (tmp[index][j] != _map[i][j]) {
						tmp[--index][j] = _map[i][j];
					}
				}
			}
		}
		/*for (int k = 0; k < N; k++) {
			for (int l = 0; l < N; l++) {
				printf("%2d", tmp[k][l]);
			}
			printf("\n");
		}
		printf("\n");*/
		func(cnt + 1, tmp, down);
	}
	
	//ÁÂ
	if (type != left) {
		int tmp[MAX][MAX] = { 0 };
		for (int i = 0; i < N; i++) {
			int index = 0;
			for (int j = 0; j < N; j++) {
				if (_map[i][j] != 0) {
					if (tmp[i][index] == 0) {
						tmp[i][index] = _map[i][j];
					}
					else if (tmp[i][index] == _map[i][j]) {
						tmp[i][index] += _map[i][j];
						index++;
					}
					else if (tmp[i][index] != _map[i][j]) {
						tmp[i][++index] = _map[i][j];
					}
				}
			}
		}
		/*for (int k = 0; k < N; k++) {
			for (int l = 0; l < N; l++) {
				printf("%2d", tmp[k][l]);
			}
			printf("\n");
		}
		printf("\n");*/
		func(cnt + 1, tmp, left);
	}

	//¿ì
	if (type != right) {
		int tmp[MAX][MAX] = { 0 };
		for (int i = 0; i < N; i++) {
			int index = N-1;
			for (int j = N-1; j >= 0; j--) {
				if (_map[i][j] != 0) {
					if (tmp[i][index] == 0) {
						tmp[i][index] = _map[i][j];
					}
					else if (tmp[i][index] == _map[i][j]) {
						tmp[i][index] += _map[i][j];
						index--;
					}
					else if (tmp[i][index] != _map[i][j]) {
						tmp[i][--index] = _map[i][j];
					}
				}
			}
		}
		/*for (int k = 0; k < N; k++) {
			for (int l = 0; l < N; l++) {
				printf("%2d", tmp[k][l]);
			}
			printf("\n");
		}
		printf("\n");*/
		func(cnt + 1, tmp, right);
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	func(0, map, first);

	printf("%d\n", ans);

	return 0;
}