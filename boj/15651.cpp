#include <iostream>

using namespace std;

int n, m;

void dupPermu(int num, int depth) {
	if (depth == m) {
		int arr[10];
		int idx = 0;
		while (num != 0) {
			arr[idx++] = num % 10;
			num /= 10;
		}
		for (int a = idx - 1; a >= 0; a--)
			printf("%d ", arr[a]);
		printf("\n");
		return;
	}
	for (int a = 1; a <= n; a++) {
		dupPermu(num * 10 + a, depth + 1);
	}
}

int main(void) {
	cin >> n;
	cin >> m;
	for (int a = 1; a <= n; a++) {
		dupPermu(a, 1);
	}
}