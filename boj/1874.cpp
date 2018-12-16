#include <iostream>
#include <cstdio>

using namespace std;

int stack[100001];
int stackIdx = -1;
int n;
int input[100001];
int ops[200001];
int opsIdx = 0;
int cur = 1;

int pop() {
	if (stackIdx == -1)
		return -1;
	ops[opsIdx++] = -1;
	return stack[stackIdx--];
}

void push(int n) {
	ops[opsIdx++] = 1;
	stack[++stackIdx] = n;
}

int peek() {
	if (stackIdx == -1)
		return -1;
	return stack[stackIdx];
}

int main() {
	scanf("%d", &n);
	for (int a = 0; a < n; a++) {
		scanf("%d", input + a);
	}
	bool isPossible = true;
	for (int a = 0; a < n; a++) {
		while (peek() < input[a])
			push(cur++);
		if (peek() == input[a])
			pop();
		else if (peek() > input[a]) {
			isPossible = false;
			break;
		}
	}
	if (isPossible) {
		for (int a = 0; a < opsIdx; a++) {
			if (ops[a] == 1)
				printf("+\n");
			else
				printf("-\n");
		}
	}
	else {
		printf("NO\n");
	}
	return 0;

}