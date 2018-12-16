#include <iostream>
using namespace std;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int w, h;
void fluidfill(int x, int y, int val, int map[51][51]) {
	if (map[x][y] != 1)
		return;
	map[x][y] = val;
	for (int a = 0; a < 4; a++) {
		int nx = x + dx[a];
		int ny = y + dy[a];
		if (0 > nx || nx >= h || 0 > ny || ny >= w)
			continue;
		if (map[nx][ny] == 1)
			fluidfill(nx, ny, val, map);
	}
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int map[51][51] = { 0, };
		int k;
		cin >> h >> w >> k;
		while (k--) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		int cnt = 2;
		for (int a = 0; a < h; a++) {
			for (int b = 0; b < w; b++) {
				if (map[a][b] == 1) {
					fluidfill(a, b, cnt, map);
					cnt++;
				}
			}
		}
		cout << cnt-2 << endl;
	}
}