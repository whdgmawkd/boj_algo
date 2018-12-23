#include <iostream>
#include <list>
using namespace std;

int n;
list<int> q;

int main() {
	cin >> n;
	for (int a = 1; a <= n; a++) {
		q.push_back(a);
	}
	while (q.size() > 1) {
		q.pop_front();
		int v = q.front();
		q.pop_front();
		q.push_back(v);
	}
	cout << q.front() << endl;
}