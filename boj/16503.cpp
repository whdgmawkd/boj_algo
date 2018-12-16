#include <iostream>
#include <cstdio>
using namespace std;

int calc(int a, char op, int b) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '/':
		return a / b;
	case '*':
		return a * b;
	}
}

int main(void) {
	int a, b, c;
	char d, e;
	scanf("%d %c %d %c %d", &a, &d, &b, &e, &c);
	int ret1 = calc(a, d, calc(b, e, c));
	int ret2 = calc(calc(a, d, b), e, c);
	if (ret1 < ret2) {
		cout << ret1 << endl << ret2 << endl;
	}
	else {
		cout << ret2 << endl << ret1 << endl;
	}
}