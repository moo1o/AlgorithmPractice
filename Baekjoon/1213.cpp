#include <iostream>

using namespace std;

char input[51];
char output[51];
int check[26];

int main(void) {
	scanf("%s", input);
	for (int i = 0; input[i] != '\0'; i++) {
		check[input[i] - 'A']++;
	}
	int c = 0;
	int odd = -1;
	for (int i = 0; i < 26; i++) {
		if (check[i] % 2 == 1) {
			c++;
			odd = i;
		}
		if (c > 1) {
			printf("I'm Sorry Hansoo\n"); 
			return 0;
		}

	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < check[i] / 2; j++) {
			output[cnt++] = 'A' + i;
		}
	}
	if (odd != -1)
		output[cnt++] = 'A' + odd;

	for (int i = 26; i >= 0; i--) {
		for (int j = 0; j < check[i] / 2; j++)
			output[cnt++] = 'A' + i;
	}

	printf("%s\n", output);



	return 0;
}