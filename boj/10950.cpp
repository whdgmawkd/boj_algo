#include <iostream>
#include <cstdio>
using namespace std;
int main(void){
	while (true) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a&&b)
			printf("%d\n", a + b);
		else
			return 0;
	}
}