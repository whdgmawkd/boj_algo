#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
double dist(int x, int y) {
	return sqrt(x * x + y * y);
}
int main(void) {
	int n;
	cin >> n;
	set<pair<double,int>> en;
	for (int a = 0; a < n; a++) {
		int x, y, v;
		scanf("%d %d %d", &x, &y, &v);
		en.insert(make_pair(dist(x, y) / v, a+1));
	}
	for (int a = 0; a < n; a++) {
		printf("%d\n", en.begin()->second);
		en.erase(en.begin());
	}
	return 0;
}