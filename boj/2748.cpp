#include <iostream>
using namespace std;

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
	int n;
	cin >> n;
	cout << fibo(n) << endl;
}