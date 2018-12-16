#include <iostream>
using namespace std;

int picture[1001][1001];

pair<int, int> picSize;
int queryCnt;

int getAvg(pair<int, int> start, pair<int, int> end) {
	int sum = 0;
	for (int x = start.first; x <= end.first; x++) {
		sum += picture[x][end.second] - picture[x][start.second - 1];
	}
	return sum / ((end.first - start.first + 1) * (end.second - start.second + 1));
}

int main(void) {
	cin >> picSize.first >> picSize.second;
	cin >> queryCnt;
	for (int a = 1; a <= picSize.first; a++) {
		for (int b = 1; b <= picSize.second; b++) {
			int tmp;
			cin >> tmp;
			picture[a][b] = picture[a][b - 1] + tmp;
		}
	}
	while (queryCnt--) {
		pair<int, int> start, end;
		cin >> start.first >> start.second >> end.first >> end.second;
		cout << getAvg(start, end) << endl;
	}
	return 0;
}