#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int reverse(int n) {
	int ret = 0;
	while (n) {
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main(void) {
	int n, k;
	cin >> n >> k;
	int ret = -1;
	for (int a = 1; a <= k; a++) {
		ret = max(ret, reverse(n*a));
	}
	cout << ret << endl;
}