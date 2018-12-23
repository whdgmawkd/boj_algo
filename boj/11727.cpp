#include <iostream>
using namespace std;

int dp[1001] = { 1,1, };

int main() {
	int n;
	cin >> n;
	for (int a = 2; a <= n; a++) {
		dp[a] = (dp[a - 1] + 2*dp[a - 2]) % 10007;
	}
	cout << dp[n] << endl;
	return 0;
}