#include <iostream>

using namespace std;

int N;
long long A, B, C, max, min = 2147483647;
char num[2147483648];
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> C >> B;
		for (long long j = 0; ; j++) {
			long long temp = A + j * B;
			if (temp > C)
				break;
			else {
				num[temp]++; 
				if (min > temp)
					min = temp;
				if (max < temp)
					max = temp;

			}
		}
	}


	return 0;
}