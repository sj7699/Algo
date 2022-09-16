#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	vector<pair<int, int>> c;
	vector<pair<int,int>>::iterator iter;
	c.push_back({1,2});
	c.push_back({ 1,-2 });
	c.push_back({ 2,1 });
	c.push_back({ 2,-1 });
	int a, b;
	int startx = 1;
	int starty = 1;
	int count = 1;
	cin >> a >> b;
	if (a == 1 || b == 1) {
	}
	else if (a == 2 && b == 2) {

	}
	else if (a < 3) {
		if (b ==5 || b==6) {
			count += 2;
		}
		else if (b > 6) {
			count = 4;
		}
		else {
			count++;
		}
	}
	else if (b == 4) {
		count = 4;
	}
	else {
		if (b < 7 || a<7) {

			for (int x = 0; x < 4; x++) {
				startx += c[x].first;
				starty += c[x].second;
				count++;
				if (x != 3) {
					if (startx + c[x + 1].first > b || starty+c[x+1].second>a) {
						break;
					}
				}
				if (x == 3) {
					count += b - startx;
				}
			}
		}
		else {
			count = b - 2;
		}
	}
	cout << count;
}