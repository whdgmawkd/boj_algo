#include <iostream>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	for (int a = n; a > 0; a--) {
		for (int b = 0; b < a; b++)
			cout << "*";
		cout << endl;
	}
	return 0;
}