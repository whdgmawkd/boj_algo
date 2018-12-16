#include <iostream>
#include <vector>
using namespace std;
bool prime[100001];
int main(void) {
	prime[0] = true;
	prime[1] = true;
	for (int a = 2; a <= 100000; a++) {
		if (!prime) {
			for (int b = a << 1; b <= 100000; b += a) {
				prime[b] = true;
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int a = 2; a <= 100000; a++) {
			if (n == 1)
				break;
			if (prime[a])
				continue;
			if (n%a == 0) {
				int cnt = 0;
				while (n%a == 0) {
					n /= a;
					cnt++;
				}
				cout << a << " " << cnt << '\n';
			}
		}
	}
	return 0;
}