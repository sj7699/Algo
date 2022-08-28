#include<iostream>
#include<algorithm>
using namespace std;
int a[300][2];
int b[300];
int main() {
	int c;
	cin >> c;
	for (int x = 0; x < c; x++) {
		cin >> b[x];
	}
	a[0][0] = b[0];
	a[0][1] = 0;
	a[1][0] = b[0]+b[1];
	a[1][1] = b[1];
	for (int x = 2; x < c; x++) {
		a[x][0] = a[x - 1][1]+b[x];
		a[x][1] = max(a[x - 2][0] + b[x], a[x - 2][1] + b[x]);
	}
	cout << max(a[c - 1][0], a[c - 1][1]);
}