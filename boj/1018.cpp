#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int h, w;
int minswap = 0x7fffffff;
bool map[51][51];

int solve(int x, int y) {
	// W as first
	int t[2] = { 0,0 };
	int f[2] = { 0,0 };
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++ ) {
			if (map[x + a][y + b])
				t[(a+b)%2]++;
			else
				f[(a+b)%2]++;
		}
	}
	return min(t[0] + f[1], t[1] + f[0]);
}

int main(void) {
	cin >> h >> w;
	for (int a = 0; a < h; a++) {
		string in;
		cin >> in;
		int len = in.size();
		for (int b = 0; b < len; b++) {
			if (in[b] == 'W')
				map[a][b] = false;
			else
				map[a][b] = true;
		}
	}
	for (int a = 0; a < h - 7; a++) {
		for (int b = 0; b < w - 7; b++) {
			minswap = min(minswap, solve(a, b));
		}
	}
	cout << minswap << endl;
}