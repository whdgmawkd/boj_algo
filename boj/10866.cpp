#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque<int> d;
int n;
string cmds[] = { "push_front", "push_back","pop_front","pop_back","size","empty","front","back" };
int main(void) {
	cin >> n;
	for (int a = 0; a < n; a++) {
		string cmd;
		cin >> cmd;
		int n;
		int idx = -1;
		for (int b = 0; b < 8; b++) {
			if (cmd.compare(cmds[b]) == 0) {
				idx = b;
				break;
			}
		}
		switch (idx) {
		case 0:
			// push front
			cin >> n;
			d.push_front(n);
			break;
		case 1:
			// push back
			cin >> n;
			d.push_back(n);
			break;
		case 2:
			// pop front
			if (d.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << d.front() << endl;
				d.pop_front();
			}
			break;
		case 3:
			// pop back
			if (d.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << d.back() << endl;
				d.pop_back();
			}
			break;
		case 4:
			// size
			cout << d.size() << endl;
			break;
		case 5:
			// empty
			cout << (d.size() == 0 ? 1 : 0) << endl;
			break;
		case 6:
			// front
			if (d.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << d.front() << endl;
			}
			break;
		case 7:
			// back
			if (d.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << d.back() << endl;
			}
			break;
		}
	}
}