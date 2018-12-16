#include <iostream>
using namespace std;
long long p[101] = { 0,1,1, };
int main(void) {
	int t;
	cin >> t;
	for (int a = 3; a <= 100; a++) {
		p[a] = p[a - 2] + p[a - 3];
	}
	while (t--) {
		int n;
		cin >> n;
		cout << p[n] << endl;
	}
}