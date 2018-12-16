#include <iostream>
using namespace std;

void hanoi(int n, int s, int m, int e) {
	if (n == 1) {
		cout << s << " " << e << '\n';
		return;
	}
	hanoi(n - 1, s, e, m);
	cout << s << " " << e << '\n';
	hanoi(n - 1, m, s, e);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';
	hanoi(n, 1, 2, 3);
}