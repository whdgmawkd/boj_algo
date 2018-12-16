#include <iostream>
using namespace std;

bool proj[10001];

int main(void) {
	int n;
	cin >> n;
	int cnt = 0;
	while (n--) {
		int s, e;
		cin >> s >> e;
		for (int a = s; a < e; a++) {
			if (proj[a])
				continue;
			proj[a] = true;
			cnt++;
		}
	}
	cout << cnt << endl;
}