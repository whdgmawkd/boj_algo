#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int map[26][26];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
vector<int> cnt;
int counter;

void fluidfill(int x, int y, int color) {
	map[x][y] = color;
	counter++;
	for (int a = 0; a < 4; a++) {
		int nx = x + dx[a], ny = y + dy[a];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
			continue;
		}
		if (map[nx][ny] == 1) {
			fluidfill(nx, ny, color);
		}
	}
}

int main(void) {
	cin >> n;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			scanf("%1d", map[a] + b);
		}
	}
	int color = 2;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (map[a][b] == 1) {
				fluidfill(a, b, color++);
				cnt.push_back(counter);
				counter = 0;
			}
		}
	}
	cout << color - 2 << endl;
	sort(cnt.begin(), cnt.end());
	for (int a : cnt) {
		cout << a << endl;
	}
}