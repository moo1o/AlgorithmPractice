#include <iostream>	

using namespace std;

void strcpy(char* dest , char* src) {
	int i;
	for (i = 0; src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
}

bool strcmp(char* a, char* b) {
	int i;
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] != b[i])
			return false;
	}
	if (b[i] != '\0')
		return false;
	return true;
}

int atoi(char* a) {
	int ret = (*a - '0');
	a++;
	while (*a != '\0') {
		ret *= 10;
		ret += (*a - '0');
		a++;
	}
	return ret;
}

void itoa(char* dest, int a) {
	char tmp[100];
	tmp[0] = '0';
	int i;
	for (i = 0; a!= 0 ; i++) {
		tmp[i] = '0' + a % 10 ;
		a /= 10;
	}
	i--;
	while (i>=0) {
		*dest = tmp[i--];
		dest++;
	}
	*dest = '\0';
}

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void bubble(int* a, int N) {
	for (int i = 0; i < N -1; i++) {
		for (int j = 0; j < N-1-i; j++) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

void select(int* a, int N) {
	for (int i = 0; i < N - 1; i++) {
		int min = i;
		for (int j = i+1; j < N; j++) {
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}


int main(void) {
	/*char a[] = "abcd";
	char b[10];
	strcpy(b, a);

	printf("%s\n", b);

	b[0] = 'b';

	if(!strcmp(b, a))
		printf("%s\n", b);

	char aa[] = "1234";
	int ii = atoi(aa);
	printf("%d\n", ii);
	char bb[100];
	itoa(bb, ii);
	
	printf("%s\n", bb);*/

	int a[] = { 55, 7, 78, 12, 42 };
	//int a[] = { 5,4,3,2,1 };
	bubble(a, 5);

	for (int i = 0; i < 5; i++) {
		printf("bubble a : %d\n", a[i]);
	}

	//int b[] = { 55, 7, 78, 12, 42 };
	int b[] = { 44, 3, 22, 5, 99 };
	select(b, 5);

	for (int i = 0; i < 5; i++) {
		printf("select b : %d\n", b[i]);
	}

	return 0;
}