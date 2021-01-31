//N±Ø 0, S±Ø 1
//È¸ÀüÈ½¼ö K , ½Ã°è¹æÇâ 1, ¹Ý½Ã°è -1
#include <iostream>	
#include <bitset>
#include <queue>
using namespace std;

int state[5];
int K;
queue<pair<int, int>> input;
int mov[5];


void print() {
	for (int i = 1; i < 5; i++)
		cout << bitset<8>(state[i]) << endl;

	printf("\n");
}

void init() {
	for (int i = 1; i < 5; i++) {
		mov[i] = 0;
	}
}

void check(int num, int dir) {
	int left = 1 << 1;
	int right = 1 << 5;
	mov[num] = dir;
	int i = num;
	int comp1, comp2;
	while (i!=1) {
		comp1 = (state[i] & left) > 0 ? 1 : 0;
		comp2 = (state[i - 1] & right) > 0 ? 1 : 0;
		
		if (comp1 == comp2)
			break;
		else
			mov[i - 1] = -mov[i];
		i--;
	}
	i = num;
	while (i != 4) {
		comp1 = (state[i] & right)  > 0 ? 1 : 0;
		comp2 = (state[i + 1] & left) > 0 ? 1 : 0;
		
		if (comp1 == comp2)
			break;
		else
			mov[i + 1] = -mov[i];
		i++;
	}


}

void rotate(int num, int dir) {
	check(num, dir);
	for(int i=1 ;i<5 ; i++)
		printf("mov[%d] : %d ", i, mov[i]);
	printf("\n");
	int save;
	for (int i = 1; i < 5; i++) {
		switch (mov[i]) {
		case -1:
			save = (state[i] & (1 << 7));
			state[i] <<= 1;
			if (save)
				state[i] += 1;
			break;

		case 1:
			save = (state[i] & 1);
			state[i] >>= 1;
			if (save)
				state[i] |= 1 << 7;
			break;
		}

		//print();
		
	}
	init();
}

int main(void) {
	for (int i = 1; i < 5; i++) {
		for (int j = 7; j >= 0; j--) {
			int in;
			scanf("%1d", &in);
			if (in) state[i] |= 1 << j;
		}
	}	
	
	scanf("%d", &K);
	
	for (int i = 0; i < K; i++) {
		int num, dir;
		scanf("%d %d", &num, &dir);
		rotate(num, dir);
		print();
	}

	
	
	int mul = 1;
	int ans = 0;
	for (int i = 1; i < 5; i++) {
		if (state[i] & 1<<7)
			ans += mul;
		mul *= 2;
	}

	printf("%d\n", ans);

	return 0;
}