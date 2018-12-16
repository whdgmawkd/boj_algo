#include <iostream>
#include <algorithm>
using namespace std;
int h[10];
bool chk[10];
int cnt;

void dfs(int lv, int sum, int cur){
	if (lv == 7) {
		if (sum == 100)
			for (int a = 0; a < 9; a++)
				if (chk[a])
					cout << h[a] << endl;
		return;
	}
	for (int a = cur; a < 9; a++) {
		if (!chk[a]) {
			chk[a] = true;
			dfs(lv + 1, sum + h[a], a);
			chk[a] = false;
		}
	}
}

int main(void) {
	for (int a = 0; a < 9; a++)
		cin >> h[a];
	sort(h, h + 9);
	for (int a = 0; a < 2; a++) {
		chk[a] = true;
		dfs(1, h[a], a);
		chk[a] = false;
	}
	return 0;
}