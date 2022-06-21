#include<iostream>
#include<vector>
using namespace std;
int team[2000];
int num = 1;
bool wonjum = false;
vector<pair<pair<int,int>,pair<int,int>>> rectangles;
int dfs(int root) {
	bool check = false;
	if (team[root]) {
		return 0;
	}
	team[root] = num;
	int x1 = rectangles[root].first.first;
	int y1 = rectangles[root].first.second;
	int x2 = rectangles[root].second.first;
	int y2 = rectangles[root].second.second;
	if (x1 == 0 && y1 == 0) {
		wonjum = true;
	}
	else if (x2 == 0 && y2 == 0) {
		wonjum = true;
	}
	else if (x1 == 0 && y2 == 0) {
		wonjum = true;
	}
	else if (x2 == 0 && y1 == 0) {
		wonjum = true;
	}
	if (y1 == 0 || y2 == 0) {
		if (x1*x2 <= 0) {
			wonjum = true;
		}
	}
	if (x1 == 0 || x2 == 0) {
		if (y1*y2 <= 0) {
			wonjum = true;
		}
	}
	for (int x = 0; x < rectangles.size(); x++) {
		int rectx1 = rectangles[x].first.first;
		int recty1 = rectangles[x].first.second;
		int rectx2 = rectangles[x].second.first;
		int recty2 = rectangles[x].second.second;
		if (x != root) {
			if ((x1 > rectx1 && y1 > recty1) && (x2 < rectx2 && y2 < recty2)) {
				check = true;
			}
			if ((x1 < rectx1 && y1 < recty1) && (x2 > rectx2 && y2 > recty2)) {
				check = true;
			}
			if ((x1 > rectx2 || y1 > recty2) || (rectx1 > x2 || recty1 > y2)) {
				check = true;

			}
		}
		if (!check) {
			dfs(x);
		}
		check = false;
	}
	return num;
}
int main() {
	int c;
	cin >> c;
	int x1, y1,x2,y2;
	for (int x = 0; x < c; x++) {
		scanf("%i%i%i%i",&x1,&y1,&x2,&y2);
		rectangles.push_back({ {x1,y1},{x2,y2} });
	}
	for (int x = 0; x < rectangles.size(); x++) {
		if (dfs(x)) {
			num++;
		}
	}
	if (wonjum) {
		num--;
	}
	printf("%i", num-1);
}