#include <iostream>

using namespace std;

int fibo(long long int n) {
	// n'th fibo num
	int prev = 0;
	int cur = 1;
	long long int cnt = 1;
	for (long long int i = 1; i < n%1500000; i++) {
		int tmp = cur;
		cur = (cur+prev)%1000000;
		prev = tmp;
		cnt++;
	}
	return cur;
}

int main(void) {
	long long int n;
	cin >> n;
	printf("%d\n", fibo(n));
	return 0;
}