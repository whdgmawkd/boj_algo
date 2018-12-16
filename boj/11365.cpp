#include <iostream>
#include <string>
using namespace std;

int main(void) {
	while (1) {
		string input;
		getline(cin, input);
		if (input.compare("END") == 0)
			return 0;
		int len = input.size();
		while (len--) {
			cout << input[len];
		}
		cout << endl;
	}
}