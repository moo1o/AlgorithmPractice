#include <iostream>
#include <vector>
using namespace std;


int main(void) {
	int n, i = 0;
	bool flag = true;
	vector<int> v;
	while (scanf("%d", &n) == 1) {
		v.push_back(n);
		if (i>0 && v[i] < v[i - 1]) {
			flag = false;
		}
		i++;
	}
	
	if (flag) {
		printf("Good\n");
	}
	else {
		printf("Bad\n");
	}

	return 0;
}