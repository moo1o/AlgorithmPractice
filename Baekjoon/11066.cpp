#include <iostream>	
#include <vector>
#include <algorithm>
using namespace std;

int ans;

int main(void) {
	int n = 2;
	vector<int> ary = {1, 21, 3, 4, 5, 35, 5, 4, 3, 5, 98, 21, 14, 17, 32};

	
	sort(ary.begin(), ary.end());
	for (int i = 0; i < 15; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	while (true) {
		int i = 0; 
		int j = ary.size()-1;
		vector<int> tmp;
		while (i <= j) {
			tmp.push_back(ary[i] + ary[j]);
			
			i++;
			j--;
		}
		sort(tmp.begin(), tmp.end());
		ary = tmp;
		tmp.clear();
		for (int i = 0; i < ary.size(); i++) {
			ans += ary[i];
			printf("%d ", ary[i]);
		}
		printf("\n");
		if (ary.size() == 1)
			break;
	}

	printf("%d\n", ans);
	return 0;
}