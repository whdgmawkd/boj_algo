#include <stack>
#include <iostream>
using namespace std;
stack<int> s;

int main(void) {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 0)
			s.pop();
		else
			s.push(n);
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum << '\n';
	return 0;
}