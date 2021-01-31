#include <iostream>
#include <memory.h>
using namespace std;

int chkCnct[1005];
int n, m;
bool twoColor; 
void init() {
	memset(chkCnct, 0, sizeof(chkCnct));
	twoColor = true;
}

int main(void) {
	int T;
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		init();
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int c1, c2;
			cin >> c1 >> c2;
			if (chkCnct[c1] == 0 && chkCnct[c2] == 0) {
				chkCnct[c1] = 1;
				chkCnct[c2] = 2;
			}
			else if (chkCnct[c1] == 0 && chkCnct[c2] != 0) {
				chkCnct[c1] = (chkCnct[c2] + 1) / 3;
			}
			else if (chkCnct[c2] == 0 && chkCnct[c1] != 0) {
				chkCnct[c2] = (chkCnct[c1] + 1) / 3;
			}
			else if(chkCnct[c1] != 0 && chkCnct[c1] == chkCnct[c2]){
				twoColor = false;
			}
			
		}
		if (twoColor) {
			cout << "possible" << endl;
		}
		else {
			cout << "impossible" << endl;
		}
	}

	return 0;
}