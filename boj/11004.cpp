#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main(void) {
	vector<int> arr;
	int n, k;
	cin >> n >> k;
	arr.resize(n);
	for (int a = 0; a < n; a++)
		scanf("%d", arr.begin() + a);
	nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
	printf("%d\n", arr[k - 1]);
	return 0;
}