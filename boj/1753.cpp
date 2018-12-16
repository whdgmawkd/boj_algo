#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> dijkstra;

int map[20001][20001];
int chk[20001];
int v, e;
int start;
int minCost = 0x7fffffff;

void bfs(int cur, int cost) {
	
}

int main(void) {
	cin >> v >> e;
	cin >> start;
	for (int a = 0; a < e; a++) {
		int u, v, w;
		cin >> u >> v >> w;
		map[u][v] = w;
	}
	
}