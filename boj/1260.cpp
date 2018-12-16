#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int map[1001][1001];
bool chkDfs[1001];
bool chkBfs[1001];

queue<int> q;

int n, m, start;

void bfs(int cur) {
	printf("%d ", cur);
	chkBfs[cur] = true;
	for (int a = 1; a <= n; a++) {
		if (!chkBfs[a] && map[cur][a] == 1) {
			chkBfs[a] = true;
			q.push(a);
		}
	}
	q.pop();
	if (q.empty())
		return;
	bfs(q.front());
}

void dfs(int cur) {
	printf("%d ", cur);
	chkDfs[cur] = true;
	for (int a = 1; a <= n; a++) {
		if (!chkDfs[a] && map[cur][a] == 1) {
			dfs(a);
		}
	}
}

int main(void) {
	cin >> n >> m >> start;
	for (int a = 0; a < m; a++) {
		int s, e;
		cin >> s >> e;
		map[s][e] = map[e][s] = 1;
	}
	dfs(start);
	printf("\n");
	q.push(start);
	bfs(q.front());
	printf("\n");
}