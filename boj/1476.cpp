#include <iostream>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	int i = 0;
	while (true) {
		int x = i % 15 + 1;
		int y = i % 28 + 1;
		int z = i % 19 + 1;
		if (x == a && y == b && z == c)
			break;
		i++;
	}
	cout << i+1 << endl;
	return 0;
}