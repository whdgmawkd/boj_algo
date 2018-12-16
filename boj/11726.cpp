#include <iostream>
using namespace std;
int dp[1001];
int n;
void solve(int cur) {
	if (cur == 1) {
		dp[cur] = 1;
		return;
	}
	if (cur == 2) {
		dp[cur] = 2;
		return;
	}
	if (cur > 0) {
		dp[cur] = (dp[cur - 1] + dp[cur - 2]) % 10007;
		return;
	}
}
int main(void) {
	cin >> n;
	for (int a = 1; a <= n; a++) {
		solve(a);
	}
	cout << dp[n] << endl;
}