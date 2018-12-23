#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> cur;
int initFloor;
int minimum = 0x7fffffff;

void elec() {
	int sum = 0;
	for (int a = 1; a < cur.size(); a++) {
		sum += (abs(initFloor - a) + a + initFloor - 2) * cur[a];
	}
	minimum = min(minimum, sum);
}

int main() {
	cin.tie();
	ios::sync_with_stdio(false);
	cin >> n;
	cur.resize(n+1);
	for (int a = 1; a <= n; a++) {
		cin >> cur[a];
	}
	for (int a = 1; a <= n; a++) {
		initFloor = a;
		elec();
	}
	cout << minimum * 2 << endl;
	return 0;
}