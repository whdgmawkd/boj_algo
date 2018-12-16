#include <iostream>
#include <string>
using namespace std;

int t;

long long fibo(int n) {
	long long cur = 1, prev = 0;
	for (int a = 1; a < n; a++) {
		long long tmp = cur;
		cur += prev;
		prev = tmp;
	}
	return cur;
}
int main(void) {
	cin >> t;
	cout << fibo(t) << endl;
}