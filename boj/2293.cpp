#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int coin[101];
int cache[10001] = { 1, };

int main() {
	cin >> n >> k;
	for (int a = 0; a < n; a++) {
		cin >> coin[a];
	}
	for (int a = 0; a < n; a++) {
		for (int b = 0; b <= k; b++) {
			if (b >= coin[a]) {
				cache[b] += cache[b - coin[a]];
			}
		}
	}
	cout << cache[k];
	return 0;
}