#include <iostream>
#include <algorithm>
using namespace std;
int stair[305];
bool chk[305];
int dp[305][2];
int n;

int main(void) {
	cin >> n;
	for (int a = 1; a <= n; a++) {
		cin >> stair[a];
	}
	dp[1][0] = stair[1];
	dp[2][0] = stair[2];
	dp[2][1] = stair[1] + stair[2];
	for (int a = 3; a <= n; a++) {
		dp[a][0] = max(dp[a - 2][0] + stair[a], dp[a - 2][1] + stair[a]);
		dp[a][1] = dp[a - 1][0] + stair[a];
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
	return 0;
}