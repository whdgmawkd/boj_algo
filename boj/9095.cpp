#include <iostream>
using namespace std;

int getcnt(int cur, int target) {
	if (cur == target)
		return 1;
	if (cur > target)
		return 0;
	return getcnt(cur + 1, target) + getcnt(cur + 2, target) + getcnt(cur + 3, target);
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << getcnt(0,n) << endl;
	}
}