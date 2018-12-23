#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> v;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (pair<int, int>& p : v) {
		printf("%d %d\n", p.first, p.second);
	}
}