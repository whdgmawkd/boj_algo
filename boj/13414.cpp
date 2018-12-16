#include <unordered_set>
#include <list>
#include <iostream>
#include <cstdio>

using namespace std;

list<int> arr;
list<int> ret;
unordered_set<int> chk;
int k, l;

int main(void) {
	cin >> k >> l;
	for (int a = 0; a < l; a++) {
		int id;
		scanf("%d", &id);
		arr.push_back(id);
	}
	for (int a = 0; a < l; a++) {
		int val = arr.back();
		arr.pop_back();
		if (chk.find(val) == chk.end()) {
			ret.push_front(val);
			chk.insert(val);
		}
	}
	for (int a = 0; a < k && !ret.empty(); a++) {
		printf("%08d\n", ret.front());
		ret.pop_front();
	}
}