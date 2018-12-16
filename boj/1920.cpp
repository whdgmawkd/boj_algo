#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n[100000];
int m;
int ns, ms;

int main(void) {
	cin >> ns;
	for (int a = 0; a < ns; a++)
		scanf("%d", n + a);
	sort(n, n + ns);
	cin >> ms;
	for (int a = 0; a < ms; a++) {
		scanf("%d", &m);
		printf("%d\n", binary_search(n, n + ns, m) ? 1 : 0);
	}
	return 0;
}