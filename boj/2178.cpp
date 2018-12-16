#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
queue<tuple<int,int,int>> bfsQueue;
int map[102][102];
bool chk[102][102];
int steps[102][102];
int h, w;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int main() {
	scanf("%d %d", &h, &w);
	for (int a = 1; a <= h; a++) {
		for (int b = 1; b <= w; b++) {
			scanf("%1d", map[a] + b);
		}
	}
	bfsQueue.push({ 1,1,2 });
	while (!bfsQueue.empty()) {
		tuple<int,int,int> pop = bfsQueue.front();
		bfsQueue.pop();
		int x = get<0>(pop), y = get<1>(pop), step = get<2>(pop);
		if (x == h && y == w) {
			cout << step - 1 << endl;
			return 0;
		}
		for (int a = 0; a < 4; a++) {
			if (map[x + dx[a]][y + dy[a]] == 1) {
				map[x + dx[a]][y + dy[a]] = step + 1;
				bfsQueue.push({ x + dx[a],y + dy[a],step + 1 });
			}
		}
	}
}
//int main(void) {
//	scanf("%d %d", &h, &w);
//	for (int a = 1; a <= h; a++) {
//		for (int b = 1; b <= w; b++) {
//			scanf("%1d", &map[a][b]);
//		}
//	}
//	bfsQueue.push({ 2,{1,1} });
//	map[1][1] = 2;
//	while (!bfsQueue.empty()) {
//		pair<int, pair<int,int>> cur = bfsQueue.front();
//		cout << cur.first << " " << cur.second.first << " " << cur.second.second << endl;
//		bfsQueue.pop();
//		if (cur.second.first == h && cur.second.second == w) {
//			cout << cur.first-1 << endl;
//			break;
//		}
//		for (int a = 0; a < 4; a++) {
//			int nx = cur.second.first + dx[a], ny = cur.second.second + dy[a];
//			if (nx < 0 || nx > h || ny < 0 || ny > w)
//				continue;
//			if (map[nx][ny] == 1)
//				map[nx][ny] = cur.first + 1;
//				bfsQueue.push({ cur.first + 1,{nx,ny} });
//		}
//	}
//}