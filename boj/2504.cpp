#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char input[31];

bool checkInput() {
	char stack[31] = {};
	int len = strlen(input);
	int idx = 0;
	for (int a = 0; a < len; a++) {
		if (input[a] == '(' || input[a] == '[')
			stack[idx++] = input[a];
		else if (input[a] == ')' && stack[idx - 1] == '(')
			idx--;
		else if (input[a] == ']' && stack[idx - 1] == '[')
			idx--;
	}
	if (idx != 0)
		return false;
	return true;
}

int getPair(int start, int length) {
	printf("getPair(%d,%d)\n", start, length);
	char stack[31] = {};
	int idx = 0;
	for (int a = start; a < length; a++) {
		if (input[a] == '(' || input[a] == '[')
			stack[idx++] = input[a];
		else if (input[a] == ')' && stack[idx - 1] == '(')
			stack[--idx] = '\0';
		else if (input[a] == ']' && stack[idx - 1] == '[')
			stack[--idx] = '\0';
		printf("%s, %d\n", stack, idx);
		if (a != start && idx == 0) {
			printf("getPair(%d, %d) -> return a+1 %d\n", start, length, a + 1);
			return a;
		}
	}
	return -1;
}

int getNum(int start, int end) {
	printf("getNum(%d, %d)\n", start, end);
	char stack[31] = {};
	int idx = 0;
	int ret = input[start] == '(' ? 2 : 3;
	if (start + 1 == end) {
		printf("getNum(%d, %d) return -> ret %d\n", start, end, ret);
		return ret;
	}
	int subNum = 0;
	int subStart = start + 1;
	int subEnd = getPair(start + 1, end);
	while (subEnd != -1) {
		subNum += getNum(subStart, subEnd);
		subStart = subEnd+1;
		subEnd = getPair(subStart, end);
	}
	printf("getNum(%d,%d) return -> ret * subNum %d\n", start, end, subNum * ret);
	return subNum * ret;
}

int main(void) {
	scanf("%s", input);
	int len = strlen(input);
	printf("%d\n", len);
	int sum = 0;
	if (checkInput()) {
		int end = getPair(0, len);
		int start = 0;
		sum = getNum(0, end);
		while (end != -1) {
			start = end+1;
			end = getPair(end, len);
			sum += getNum(start, end);
		}
		printf("%d\n", sum);
	}
	else
		printf("0\n");
	return 0;
}