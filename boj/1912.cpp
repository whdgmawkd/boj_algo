#include <iostream>

using namespace std;

long long dp[100001];
int num[100001];

long long max(long long a, long long b) {
	return a > b ? a : b;
}

int main(void) {
	int n;
	cin >> n;
	for (int a = 0; a < n; a++)
		cin >> num[a];
	dp[0] = num[0];
	long long ret = dp[0];
	for (int a = 1; a < n; a++) {
		dp[a] = max(dp[a - 1] + num[a], num[a]);
		ret = max(dp[a], ret);
	}
	printf("%ld\n", ret);
	return 0;
}