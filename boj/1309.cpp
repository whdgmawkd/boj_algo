#include <iostream>

using namespace std;

int dp[100001][3] = { {1,1,1}, };
int n;

int main(void) {
	cin >> n;
	for (int a = 1; a < n; a++) {
		dp[a][1] = (dp[a - 1][0] + dp[a - 1][2]) % 9901;
		dp[a][2] = (dp[a - 1][0] + dp[a - 1][1]) % 9901;
		dp[a][0] = (dp[a - 1][0] + dp[a-1][1] + dp[a-1][2]) % 9901;
	}
	printf("%d\n", (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2])%9901);
	return 0;
}