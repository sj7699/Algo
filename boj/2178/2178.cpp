#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int maze[101][101];
bool check[101][101];
int _count = 0;
int size_n = 0;
int size_m = 0;
queue<int> Q;
int bfs(int startx,int starty) {
	int tempx, tempy;
	int step = 0;
	Q.push(startx);
	Q.push(starty);
	Q.push(step);
	while (!Q.empty()) {
		tempx = Q.front();
		Q.pop();
		tempy = Q.front();
		Q.pop();
		step = Q.front();
		Q.pop();
		if (tempx == size_m - 1 && tempy == size_n - 1) {
			step++;
			return step;
		}
		check[tempx][tempy] = true;
		if (tempx >= 1) {
			if (!check[tempx - 1][tempy] && maze[tempx - 1][tempy] != 0) {
				Q.push(tempx-1);
				Q.push(tempy);
				Q.push(step+1);
				check[tempx-1][tempy] = true;
			}
		}
		if (tempx <= size_m - 2) {
			if (!check[tempx + 1][tempy] && maze[tempx + 1][tempy] != 0) {
				Q.push(tempx+1);
				Q.push(tempy);
				Q.push(step+1);
				check[tempx+1][tempy] = true;
			}
		}
		if (tempy >= 1) {
			if (!check[tempx][tempy - 1] && maze[tempx][tempy - 1] != 0) {
				Q.push(tempx );
				Q.push(tempy-1);
				Q.push(step + 1);
				check[tempx][tempy-1] = true;
			}
		}
		if (tempy <= size_n- 2) {
			if (!check[tempx][tempy + 1] && maze[tempx][tempy + 1] != 0) {
				Q.push(tempx );
				Q.push(tempy+1);
				Q.push(step + 1);
				check[tempx][tempy+1] = true;
			}
		}
	}
	return step;
}
int main() {
	int m, n,step;
	string temp;
	cin >> m >> n;
	size_m = m;
	size_n = n;
	getline(cin, temp);
	for (int x = 0; x < m; x++) {
		getline(cin, temp);
		for (int y = 0; y < n; y++) {
			maze[x][y] = temp[y]-'0';
		}
	}
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			check[x][y] = false;
		}
	}
	step = bfs(0, 0);
	printf("%i", step);
}