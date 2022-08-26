#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool check[25][25];
int house[25][25];
int villagenumber = 1;
int _count = 0;
int hsize = 0;
int howmany_vilage[700];
bool findvillage(int startx, int starty, int b) {
	if (check[startx][starty] || house[startx][starty] == 0) {
		return false;
	}
	check[startx][starty] = true;
	house[startx][starty] = b;
	howmany_vilage[b]++;
	if (startx - 1 >= 0) {
		if (house[startx - 1][starty] != 0) {
			findvillage(startx - 1, starty, b);
		}
	}
	if (startx + 2 <= hsize) {
		if (house[startx + 1][starty] != 0) {
			findvillage(startx + 1, starty, b);
		}
	}
	if (starty - 1 >= 0) {
		if (house[startx][starty - 1] != 0) {
			findvillage(startx, starty - 1, b);
		}
	}
	if (starty + 2 <= hsize) {
		if (house[startx][starty + 1] != 0) {
			findvillage(startx, starty + 1, b);
		}
	}
	return true;
}
int main() {
	int tsize;
	string temp;
	cin >> tsize;
	hsize = tsize;
	getline(cin, temp);
	for (int x = 0; x < tsize; x++) {
		getline(cin, temp);
		for (int y = 0; y < tsize; y++) {
			house[x][y] = temp[y] - '0';
		}
	}
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 25; y++) {
			check[x][y] = false;
		}
	}
	for (int x = 0; x < tsize; x++) {
		for (int y = 0; y < tsize; y++) {
			if (findvillage(x, y, villagenumber)) {
				villagenumber++;
			}
		}

	}
	printf("%i\n", villagenumber - 1);
	sort(howmany_vilage + 1, howmany_vilage + villagenumber);
	for (int x = 1; x <= villagenumber - 1; x++) {
		printf("%i\n", howmany_vilage[x]);
	}
}