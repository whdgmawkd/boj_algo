#include <iostream>
#include <cstring>

using namespace std;

char input[51];
int cur = 0;

int main(void) {
	int n;
	scanf("%d", &n);
	for (int a = 0; a < n; a++) {
		cur = 0;
		scanf("%s", input);
		int len = strlen(input);
		for (int b = 0; b < len; b++) {
			if (input[b] == '(')
				cur++;
			else if (cur <= 0 && input[b] == ')') {
				cur = -987654321;
				break;
			}
			else if (input[b] == ')')
				cur--;
		}
		if (cur == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}