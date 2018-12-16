#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001] = { 0,0,1,1 };

int main(void) {
	int n;
	cin >> n;
	for (int a = 4; a <= n; a++) {
		dp[a] = dp[a - 1] + 1;
		if (a % 3 == 0)
			dp[a] = min(dp[a / 3] + 1, dp[a]);
		if (a % 2 == 0)
			dp[a] = min(dp[a / 2] + 1, dp[a]);
	}
	cout << dp[n] << endl;
}