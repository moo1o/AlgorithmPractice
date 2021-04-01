#include <iostream>
#include <queue>
#include <functional>
#define odd 1
#define even 0
using namespace std;

int mid;
priority_queue<int, vector<int>, greater<int>> R;
priority_queue<int, vector<int>, less<int>> L;
int K; 
void solution(int num) {
	if (num > mid) {
		if (R.size() > L.size()) {
			L.push(mid);
			if (R.top() < num) {
				mid = R.top();
				R.pop();
				R.push(num);
			}
			else {
				mid = num;
			}			
		}
		else if (R.size() <= L.size()) {
			R.push(num);
		}
	}
	else if (num < mid) {
		if (R.size() > L.size()) {
			L.push(num);
		}
		else if (R.size() <= L.size()) {
			R.push(mid);
			if (L.size()!=0 && L.top() > num) {
				mid = L.top();
				L.pop();
				L.push(num);
			}
			else {
				mid = num;
			}
		}
	}
	else if (num == mid) {
		if (R.size() >= L.size()) {
			L.push(num);
		}
		else if (R.size() < L.size()) {
			R.push(num);
		}
	}
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N; 
	//cin >> N;
	scanf("%d", &N);
	int num;
	//cin >> num;
	scanf("%d", &num);
	mid = num;
	//cout << mid << endl;
	printf("%d\n", mid);
	for (int i = 1; i < N; i++) {
		//cin >> num;
		scanf("%d", &num);
		solution(num);
		//cout << mid << endl;
		printf("%d\n", mid);
	}

	return 0;
}