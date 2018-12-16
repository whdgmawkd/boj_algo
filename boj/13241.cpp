#include <iostream>

typedef long long ll;

using namespace std;

ll a, b;

ll gcd(ll i, ll j) {
	while (j != 0) {
		int k = i % j;
		i = j;
		j = k;
	}
	return i;
}

ll lcm(ll i, ll j) {
	return (i*j) / gcd(i, j);
}

int main(void) {
	cin >> a >> b;
	printf("%ld\n", lcm(a, b));
	return 0;
}