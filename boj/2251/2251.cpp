#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> a0cit;
void bfs(int a, int b,int c) {
	queue<pair<int,int>> Q;
	int max_water = c;
	bool check[201][201];
	for (int x = 0; x < 201; x++) {
		for (int y = 0; y < 201; y++) {
			check[x][y] = false;
		}
	}
	if (c > a) {
		Q.push({ a,0 });
		check[a][0] = true;
	}
	else {
		Q.push({ c,0 });
		check[c][0] = true;
	}
	if (c > b) {
		Q.push({ 0,b });
		check[0][b] = true;
	}
	else {
		Q.push({ 0,c });
		check[0][c] = true;
	}
	while (!Q.empty()) {
		int tempa = Q.front().first;
		int tempb = Q.front().second;
		Q.pop();
		int tempc = max_water - tempa - tempb;
		int tempa2;
		int tempb2;
		int tempc2;
		if (tempa == 0) {
			a0cit.push_back(tempc);
		}
		if (tempa != 0) {
				if (tempa >= b - tempb) {
					tempa2 = tempa - (b - tempb);
					tempb2 = b;
					if (!check[tempa2][tempb2]) {
						Q.push({ tempa2,tempb2 });
						check[tempa2][tempb2] = true;
					}
				}
				else {
					tempa2 = 0;
					tempb2 = tempb + tempa;
					if (!check[tempa2][tempb2]) {
						Q.push({ tempa2,tempb2 });
						check[tempa2][tempb2] = true;
					}
				}
				if (tempa >= c - tempc) {
					tempa2 = tempa - (c - tempc);
					if (!check[tempa2][tempb]) {
						Q.push({ tempa,tempb });
						check[tempa2][tempb] = true;
					}
				}
				else {
					tempa2 = 0;
					if (!check[tempa2][tempb]) {
						Q.push({ tempa2,tempb });
						check[tempa2][tempb] = true;
					}
				}
		}
		if (tempb != 0) {
				if (tempb >= a - tempa) {
					tempb2 = tempb - (a - tempa);
					tempa2 = a;
					if (!check[tempa2][tempb2]) {
						Q.push({ tempa2,tempb2 });
						check[tempa2][tempb2] = true;
					}
				}
				else {
					tempb2 = 0;
					tempa2 = tempb + tempa;
					if (!check[tempa2][tempb2]) {
						Q.push({ tempa2,tempb2 });
						check[tempa2][tempb2] = true;
					}
				}
			}
				if (tempb >= c - tempc) {
					tempb2 = tempb - (c - tempc);
					if (!check[tempa][tempb2]) {
						Q.push({ tempa,tempb2 });
						check[tempa][tempb2] = true;
					}
				}
				else {
					tempb2 = 0;
					if (!check[tempa][tempb2]) {
						Q.push({ tempa,tempb2 });
						check[tempa][tempb2] = true;
					}
				}
		if (tempc != 0) {
				if (tempc >= b - tempb) {
					tempb2 = b;
					if (!check[tempa][tempb2]) {
						Q.push({ tempa,tempb2 });
						check[tempa][tempb2] = true;
					}
				}
				else {
					tempb2 = tempb + tempc;
					if (!check[tempa][tempb2]) {
						Q.push({ tempa,tempb2 });
						check[tempa][tempb2] = true;
					}
				}
			}
				if (tempc >= a - tempa) {
					tempa2 = a;
					if (!check[tempa2][tempb]) {
						Q.push({ tempa2,tempb });
						check[tempa2][tempb] = true;
					}
				}
				else {
					tempa2 = tempa + tempc;
					if (!check[tempa2][tempb]) {
						Q.push({ tempa2,tempb });
						check[tempa2][tempb] = true;
					}
				}
		
	}

}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	a0cit.push_back(c);
	bfs(a, b, c);
	sort(a0cit.begin(), a0cit.end());
	for (int x = 0; x < a0cit.size(); x++) {
		printf("%i ", a0cit[x]);
	}
}