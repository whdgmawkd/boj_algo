#include <iostream>
using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie();
	int n;
	long long sum = 0;
	cin >> n;
	n *= n;
	for (int a = 0; a < n; a++) {
		int tmp;
		cin >> tmp;
		sum += tmp;
	}
	cout << sum << endl;
	return 0;
}