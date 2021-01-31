#include <cstdio>
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

string in;
vector<pair<int, int>> bracket;
stack<int> st;
set<string> out;
vector<int> check;


void func(int c, int cnt) {
	if (bracket.size() == c) {
		string temp = "";
		for (int i = 0; i < in.length(); i++) {
			if (check[i] == 0) {
				temp += in[i];
			}
		}
		out.insert(temp);
		return;
	}
	func(c + 1, cnt);
	check[bracket[c].first] = 1;
	check[bracket[c].second] = 1;
	func(c + 1, cnt + 1);
	check[bracket[c].first] = 0;
	check[bracket[c].second] = 0;
}


int main(void) {
	cin >> in;
	for (int i = 0; i<in.length(); i++) {

		if (in[i] == '(') {
			st.push(i);
		}
		else if (in[i] == ')') {
			bracket.push_back({ st.top(), i });
			st.pop();
		}
	}
	check.resize(in.length());
	func(0, 0);
	out.erase(in);

	for (auto s : out) {
		cout << s << endl;
	}



	return 0;
}