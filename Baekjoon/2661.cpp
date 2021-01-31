#include <iostream>
#include <string>
using namespace std;

int N;

bool check(string num) {
	int len = num.length();
	int start = len - 1;

	for (int i = 1; i <= len / 2; i++) {
		string first = num.substr(start - i, i);
		string second = num.substr(start, i);
		if (first == second)
			return false;
		start--;
	}
	return true;
}


void func(int k, string num) {
	if (!check(num)) 
		return;
	if (N == k) {
		cout << num << endl;
		exit(0);
	}
	func(k + 1, num + "1");
	func(k + 1, num + "2");
	func(k + 1, num + "3");
}


int main(void) {
	cin >> N;
	
	func(1, "1");
	return 0;
}