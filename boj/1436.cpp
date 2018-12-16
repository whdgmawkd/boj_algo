#include <iostream>
using namespace std;
int num[10];
void up(int digit) {
	if (num[digit] == 9) {
		num[digit] = 0;
		up(digit + 1);
		return;
	}
	num[digit]++;
}
int main(void) {
	int n;
	cin >> n;
	num[0] = num[1] = num[2] = 6;
	while (true) {
		for (int a = 2; a < 10; a++) {
			if (num[a] == 6 && num[a - 1] == 6 && num[a - 2] == 6) {
				n--;
				break;
			}
		}
		if (n == 0)
			break;
		up(0);
	}
	bool flag = false;
	for (int a = 9; a >= 0; a--) {
		if (!flag && num[a] != 0)
			flag = true;
		if (flag) {
			cout << num[a];
		}
	}
	cout << endl;
	return 0;
}