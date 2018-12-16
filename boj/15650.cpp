#include <iostream>

using namespace std;

int n, m;
bool check[10];

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
	for (int a = num%10+1; a <= n; a++) {
		if (check[a])
			continue;
		check[a] = true;
		dupPermu(num * 10 + a, depth + 1);
		check[a] = false;
	}
}

int main(void) {
	cin >> n;
	cin >> m;
	for (int a = 1; a <= n; a++) {
		check[a] = true;
		dupPermu(a, 1);
		check[a] = false;
	}
}