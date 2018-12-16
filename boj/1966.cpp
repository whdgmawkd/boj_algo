#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int a = 0; a < n; a++) {
		int m, target;
		cin >> m >> target;
		deque<pair<int, int>> dq;
		for (int b = 0; b < m; b++) {
			int p;
			cin >> p;
			dq.push_back(make_pair(p, b));
		}
		int popCnt = 1;
		while (true) {
			bool flag = false;
			for (int b = 1; b < dq.size(); b++) {
				if (dq[0].first < dq[b].first) {
					flag = true;
				}
			}
			if (flag) {
				pair<int, int> tmp = dq[0];
				dq.pop_front();
				dq.push_back(tmp);
				continue;
			}
			if (dq.front().second == target) {
				break;
			}
			dq.pop_front();
			popCnt++;
		}
		printf("%d\n", popCnt);
	}
}
