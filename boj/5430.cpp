#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void input(vector<int> &arr) {
	string in;
	cin >> in;
	int len = in.size();
	int val = 0;
	for (int a = 0; a < len; a++) {
		if (in[a] == '[')
			continue;
		if ((in[a] == ',' || in[a] == ']') && val!=0) {
			arr.push_back(val);
			val = 0;
			continue;
		}
		val *= 10;
		val += in[a] - '0';
	}
}

pair<bool,pair<int,int>> ac(vector<int> &arr, string cmd) {
	int len = cmd.size();
	int l = 0;
	int r = arr.size();
	bool rev = false;
	bool error = false;
	for (int a = 0; a < len; a++) {
		if (cmd[a] == 'R')
			rev = !rev;
		if (cmd[a] == 'D') {
			if (!rev) {
				l++;
			}
			else {
				r--;
			}
		}
		if (r < l) {
			return { false,{-1,-1} };
		}
	}
	return { !rev ,{l,r} };
}

void print(vector<int> &arr, pair<bool, pair<int, int>> range) {
	int len = arr.size();
	int s = range.second.first;
	int e = range.second.second;
	bool chk = true;
	if (range.second.first == -1 && range.second.second == -1) {
		cout << "error" << endl;
		return;
	}
	cout << '[';
	if (range.first) {
		for (int a = s; a < e; a++) {
			if (chk) {
				chk = false;
				cout << arr[a];
			}
			else
				cout << ',' << arr[a];
		}
	}
	else {
		for (int a = e-1; a >= s; a--) {
			if (chk) {
				cout << arr[a];
				chk = false;
			}
			else
				cout << ',' << arr[a];
		}
	}
	cout << ']' << endl;
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		string p;
		cin >> p;
		int n;
		cin >> n;
		pair<bool, pair<int,int>> range;
		vector<int> arr;
		input(arr);
		range = ac(arr, p);
		print(arr, range);
	}
}

/*
void ac(deque<int> q, string cmd) {
	int len = cmd.size();
	bool reverse = false;
	for (int i = 0; i < len; i++) {
		if (cmd[i] == 'D' && q.empty()) {
			cout << "error" << endl;
			return;
		}
		if (cmd[i] == 'R')
			reverse = !reverse;
		else if (cmd[i] == 'D') {
			if (reverse) {
				q.pop_back();
			}
			else {
				q.pop_front();
			}
		}
	}
	cout << '[';
	while (q.size() > 1) {
		if (reverse) {
			cout << q.back() << ',';
			q.pop_back();
		}
		else {
			cout << q.front() << ',';
			q.pop_front();
		}
	}
	if(!q.empty())
		cout << q.front();
	cout << ']' << endl;
	return;
}

void input(deque<int> &q) {
	string in;
	cin >> in;
	int len = in.size();
	int val = 0;
	for (int a = 0; a < len; a++) {
		if (in[a] == '[')
			continue;
		if (in[a] == ',' || in[a] == ']') {
			q.push_back(val);
			val = 0;
			continue;
		}
		val *= 10;
		val += in[a] - '0';
	}
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		deque<int> q;
		string p;
		cin >> p;
		int n;
		cin >> n;
		input(q);
		ac(q, p);
	}
}
*/