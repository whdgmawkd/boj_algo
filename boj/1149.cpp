#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int R = 0, G = 1, B = 2;
int dp[1001][3];

void calc(int cur,int r,int g,int b) {
	dp[cur][R] = min(dp[cur - 1][B], dp[cur - 1][G]) + r;
	dp[cur][G] = min(dp[cur - 1][R], dp[cur - 1][B]) + g;
	dp[cur][B] = min(dp[cur - 1][R], dp[cur - 1][G]) + b;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	for (int a = 1; a <= n; a++) {
		int r, g, b;
		cin >> r >> g >> b;
		calc(a,r,g,b);
	}
	cout << min(min(dp[n][R], dp[n][G]), dp[n][B]) << endl;
	return 0;
}