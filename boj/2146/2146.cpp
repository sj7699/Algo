#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> store;
int map[101][101];
bool check[101][101];
int cnum = 1;
int map_size = 0;
bool dfs(int startx, int starty, int num) {
	if (check[startx][starty] || map[startx][starty]==0) {
		return false;
	}
	check[startx][starty] = true;
	map[startx][starty] = num;
	if (startx - 1 >= 0) {
		if (!check[startx - 1][starty] && map[startx-1][starty]!=0) {
			dfs(startx - 1, starty, num);
		}
	}
	if (startx  <= map_size-2) {
		if (!check[startx +1][starty] && map[startx + 1][starty]!=0) {
			dfs(startx + 1, starty, num);
		}
	}
	if (starty - 1 >= 0) {
		if (!check[startx][starty-1] && map[startx ][starty-1]!=0) {
			dfs(startx, starty-1, num);
		}
	}
	if (starty <= map_size - 2) {
		if (!check[startx][starty + 1] && map[startx][starty + 1]!=0) {
			dfs(startx, starty + 1, num);
		}
	}
	return true;
}
int bfs(int startx, int starty,int num) {
	int tempx, tempy;
	int step = 0;
	bool bcheck[101][101];
	for (int x = 0; x < 101; x++) {
		for (int y = 0; y < 101; y++) {
			bcheck[x][y] = false;
		}
	}
	queue<int> Q;
	Q.push(startx);
	Q.push(starty);
	Q.push(step);
	bcheck[startx][starty] = true;
	while (!Q.empty()) {
		tempx = Q.front();
		Q.pop();
		tempy = Q.front();
		Q.pop();
		step = Q.front();
		Q.pop();
		if (map[tempx][tempy] != num && map[tempx][tempy] > 0) {
			return step;
		}
		if (tempx >= 1) {
			if (map[tempx - 1][tempy] != num && !bcheck[tempx-1][tempy]) {
				Q.push(tempx-1);
				Q.push(tempy);
				Q.push(step+1);
                bcheck[tempx-1][tempy] = true;
			}
		}
		if (tempx <= map_size-2) {
			if (map[tempx +1][tempy] != num && !bcheck[tempx + 1][tempy]) {
				Q.push(tempx + 1);
				Q.push(tempy);
				Q.push(step + 1);
                bcheck[tempx+1][tempy] = true;
			}
		}
		if (tempy >= 1) {
			if (map[tempx][tempy-1] != num && !bcheck[tempx][tempy-1]) {
				Q.push(tempx);
				Q.push(tempy - 1);
				Q.push(step + 1);
                bcheck[tempx][tempy-1] = true;
			}
		}
		if (tempy <=map_size-2) {
			if (map[tempx][tempy+1] != num && !bcheck[tempx][tempy+1]) {
				Q.push(tempx );
				Q.push(tempy + 1);
				Q.push(step + 1);
                bcheck[tempx][tempy+1] = true;
			}
		}
	}
	return 100000;
}
int main() {
	int size,temp;
	cin >> size;
	map_size = size;
	for (int x = 0; x < map_size; x++) {
		for (int y = 0; y < map_size; y++) {
			cin >> map[x][y];
		}
	}
	for (int x = 0; x < map_size; x++) {
		for (int y = 0; y < map_size; y++) {
			if (dfs(x, y, cnum)) {
				cnum++;
			}
		}
	}
	for (int x = 0; x < map_size; x++) {
		for (int y = 0; y < map_size; y++) {
			if (map[x][y] != 0) {
				temp = bfs(x, y, map[x][y]);
				if (temp != 0) {
					store.push_back(temp);
				}
			}
		}
	}
	sort(store.begin(), store.end());
	cout << store[0]-1;

}