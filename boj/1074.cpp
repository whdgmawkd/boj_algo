#include <iostream>
using namespace std;
int N, r, c;
int cnt;


void find(int n, int x, int y) {
	if (x == r && y == c) {
		cout << cnt << endl;
		return;
	}
	if (x <= r && r < x + n && y <= c && c < y + n) {
		find(n / 2, x, y);
		find(n / 2, x, y + n / 2);
		find(n / 2, x + n / 2, y);
		find(n / 2, x + n / 2, y + n / 2);
	}
	else {
		cnt += n * n;
	}
}

int main(void) {
	cin >> N >> r >> c;
	find((1 << N), 0, 0);
}