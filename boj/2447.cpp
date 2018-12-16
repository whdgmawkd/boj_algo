#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char map[2200][2200];
int n;
int dx[] = { 0,0,0,1,1,2,2,2 };
int dy[] = { 0,1,2,0,2,0,1,2 };

void draw(int x, int y, int size) {
	cout << size << endl;
	if (size == 3) {
		for (int a = 0; a < 8; a++) {
			map[x + dx[a]][y + dy[a]] = '*';
		}
		return;
	}
	size /= 3;
	for (int a = 0; a < 8; a++) {
		draw(x + dx[a] * size, y + dy[a] * size, size);
	}
}

int main() {
	cin >> n;
	for (int a = 0; a < n; a++) {
		memset(map[a], ' ', n);
	}
	draw(0, 0, n);
	/*for (int a = 0; a < n; a++) {
		printf("%s\n", map[a]);
	}*/
	return 0;
}