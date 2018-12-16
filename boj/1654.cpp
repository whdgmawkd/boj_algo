#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
long long m,k;
vector<long long> arr;

long long check(long long len) {
	long long cnt = 0;
	for (long long el : arr) cnt += el / len;
	return cnt;
}

int main(void) {
	cin >> n >> k;
	arr.resize(n+1);
	for (int a = 1; a <= n; a++) scanf("%lld", &arr[a]);
	m = *max_element(arr.begin()+1, arr.end());
	long long left = 1, right = m+1;
	while (left < right) {
		long long mid = (left + right) / 2;
		if (check(mid) < k) {
			right=mid;
		}
		else {
			left = mid+1;
		}
	}
	printf("%lld\n", right-1);
	return 0;
}