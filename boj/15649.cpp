#include <iostream>

using namespace std;

int n, m;
bool check[9];
int last_check = 0;
int ret[9];
int retIdx;

void dfs(int);

int main(void) {
	cin >> n >> m;

	dfs(0);

	return 0;
}

void dfs(int cur) {
	if (cur == m) {
		for (int a = 0; a < retIdx; a++) {
			cout << ret[a] << " ";
		}
		cout << '\n';
		return;
	}
	for (int b = 1; b <= n; b++) {
		if (check[b])
			continue;
		check[b] = true;
		ret[retIdx++] = b;
		dfs(cur + 1);
		ret[retIdx--] = 0;
		check[b] = false;
	}
}
