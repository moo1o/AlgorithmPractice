#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define MAX 1000
using namespace std;

int N;
struct INFO {
	string name;
	int myindex;
	int rank;
	pair<string, int> parent;
	vector<string> child;
};
vector<INFO> dir;
map<string, int> findindex;
int check[MAX];

bool comp1(const INFO& a, const INFO& b) {
	if (a.rank < b.rank) {
		return true;
	}
	else if (a.rank == b.rank && a.name < b.name) {
		return true;
	}
	return false;
}

bool comp2(const string& a, const string& b) {
	if (a < b) {
		return true;
	}
	return false;
}

int mfind(string name, int par) {
	for (int i = 0; i < dir.size(); i++) {
		//if (check[i]) continue;
		if (dir[i].name == name && (par == -1 || dir[i].parent.second == par)) {
			return i;
		}
	}
	return -1;
}

int mfind(string name) {
	for (int i = 0; i < dir.size(); i++) {
		if (dir[i].name == name) {
			return dir[i].myindex;
		}
	}
	return -1;
}

bool comp_parent(int idx, string parent) {
	if (dir[idx].parent.first == parent && dir[idx].parent.second == mfind(parent)) {
		return true;
	}
	else {
		return false;
	}
}


void print_dir(int k) {
	check[k] = 1;
	for (int i = 1; i < dir[k].rank; i++) {
		cout << " ";
	}
	cout << dir[k].name << endl;
	int childsz = dir[k].child.size();
	if (childsz) {
		sort(dir[k].child.begin(), dir[k].child.end(), comp2);
		for (int i = 0; i < childsz; i++) {
			print_dir(mfind(dir[k].child[i], dir[k].myindex));
		}
	}
	return;
}

void solve() {
	sort(dir.begin(), dir.end(), comp1);
	for (int i = 0; i < dir.size(); i++) {
		if (check[i]) continue;
		print_dir(i);
	}
}



int main(void) {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int st = 0;
		int rank = 1;
		queue<string> save;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '\\' || j == str.length() - 1) {
				int size = j == str.length() - 1 ? j + 1 - st : j - st;
				string word = str.substr(st, size);
				save.push(word);
				string parent = rank>1 ? save.front() : word;
				int myindex = dir.size();
				//존재 하지 않거나 , 랭크가 다르거나 , 부모가 다르면
				if (findindex.find(word) == findindex.end() || rank != dir[findindex[word]].rank || !comp_parent(findindex[word], parent)) {
					int paridx = myindex;
					if (save.size() == 2) {
						parent = save.front();
						paridx = mfind(parent);
						dir[paridx].child.push_back(word);
						save.pop();
					}
					findindex[word] = myindex;
					dir.push_back({ word, myindex,rank, make_pair(parent,paridx), vector<string>(0) });
				}
				else {
					if (save.size() >1)
						save.pop();
				}
				rank++;
				st = j + 1;
			}
		}
	}

	solve();

	return 0;
}