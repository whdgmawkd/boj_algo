#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min(min(x, y), min(abs(w - x), abs((y - h)))) << '\n';
}
