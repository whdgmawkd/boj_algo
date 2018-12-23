#include <iostream>
#include <map>
using namespace std;

long long n;
long long p, q;
map<long long, long long> dp;

long long rec(long long i) {
	if (dp[i])
		return dp[i];
	return dp[i] = rec(i / p) + rec(i / q);
}

int main() {
	cin >> n >> p >> q;
	dp[0] = 1;
	cout << rec(n) << endl;
	return 0;
}