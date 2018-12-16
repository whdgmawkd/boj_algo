#include <iostream>
using namespace std;

bool chk[101];
int graph[101][101];
int pcCnt;
int wireCnt;

int virus(int pc) {
	int infected = 1;
	chk[pc] = true;
	for (int a = 1; a <= pcCnt; a++) {
		if (graph[pc][a] && !chk[a]) {
			infected += virus(a);
		}
	}
	return infected;
}

int main(void) {
	cin >> pcCnt;
	cin >> wireCnt;
	while (wireCnt--) {
		int from, to;
		cin >> from >> to;
		graph[from][to] = graph[to][from] = true;
	}
	cout << virus(1)-1 << endl;
	return 0;
}