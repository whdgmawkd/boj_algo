#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long s;
vector<long long> v;
long long d;
long long m = 0x7fffffffffffffff;

long long find(long long e) {
	long long l = 0, r = e;
	long long mid = 0;
	while (l < r) {
		mid = (l + r) / 2;
		long long di = d * (mid+1);
		if (di < s) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return m-r;
}

int main() {
	ios::sync_with_stdio(false);
	long long sum = 0;
	cin >> n >> s;
	v.resize(n);
	for (int a = 0; a < n; a++) {
		cin >> v[a];
		sum += v[a];
		m = min(m, v[a]);
	}
	d = sum - m * n;
	if (sum < s) {
		cout << -1 << endl;
		return 0;
	}
	cout << find(m) << endl;
	return 0;
}