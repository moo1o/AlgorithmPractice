#include <cstdio>

using namespace std;

int slec[10];
int chk[10];

void perm(int n, int k, int m) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", slec[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (chk[i] == 0) {
			slec[k] = i + 1;
			chk[i] = 1;
			perm(n, k + 1, m);
			chk[i] = 0;
		}
	}
}


int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	perm(N, 0, M);


	return 0;
}



//#include <iostream>
//
//using namespace std;
//
//int slec[10];
//int chk[10];
//
//void perm(int n, int k, int m) {
//	if (k == m) {
//		for (int i = 0; i < m; i++) {
//			cout << slec[i] << " ";
//		}
//		cout << endl;
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		if (chk[i] == 0) {
//			slec[k] = i + 1;
//			chk[i] = 1;
//			perm(n, k + 1, m);
//			chk[i] = 0;
//		}	
//	}
//}
//
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int N, M;
//	cin >> N >> M;
//	perm(N, 0, M);
//
//
//	return 0;
//}