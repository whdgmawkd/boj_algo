#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int target;
int current = 100;
int broken;
int brokenbtn[10];
int minimumcnt;

int get_digit_count(int n) {
	int digit = 0;
	while (n != 0) {
		digit++;
		n /= 10;
	}
	return digit;
}

void gen_num(int num, int press) {
	if (num == 0 && press!=1) return;
	int tmp = abs(target - num);
	tmp += press;
	//tmp += get_digit_count(num);
	minimumcnt = tmp < minimumcnt ? tmp : minimumcnt;
	if (num>1000001) {
		return;
	}
	for (int a = 0; a < 10; a++) {
		if (brokenbtn[a] == 0)
			gen_num(num * 10 + a, press+1);
	}
	return;
}

int main(void) {
	scanf("%d", &target);
	scanf("%d", &broken);
	for (int a = 0; a < broken; a++) {
		int idx;
		scanf("%d", &idx);
		brokenbtn[idx] = 1;
	}
	int start=0;
	for (int a = 0; a < 10; a++) {
		if (brokenbtn[a] == 0) {
			start = a;
			break;
		}
	}
	minimumcnt = abs(current - target);
	for (int a = 0; a < 10; a++) {
		if (brokenbtn[a] == 0)
			gen_num(a,1);
	}
	printf("%d\n", minimumcnt);
}