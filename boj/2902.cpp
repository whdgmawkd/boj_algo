#include <iostream>
#include <string>
using namespace std;
int main(void) {
	string in;
	cin >> in;
	int len = in.size();
	for (int a = 0; a < len; a++) {
		if ('A' <= in[a] && in[a] <= 'Z')
			cout << in[a];
	}
	cout << endl;
}