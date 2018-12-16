#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int t;
int main(void) {
	cin >> t;
	for (int a = 0; a < t; a++) {
		int n;
		int cnt = 0;
		vector<int> dot;
		unordered_set<int> chk;
		scanf("%d", &n);
		for (int b = 0; b < n; b++) {
			int val;
			scanf("%d", &val);
			dot.push_back(val);
			chk.insert(val);
		}
		sort(dot.begin(), dot.end());
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int third = dot[j] + (dot[j] - dot[i]);
				if (chk.find(third) != chk.end()) {
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}