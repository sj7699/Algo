#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int pizza1[1000];
int pizza2[1000];
vector<int> pizzasum1;
vector<int> pizzasum2;
int main() {
	int count = 0;
	int S, pizza1n, pizza2n;
	scanf("%i%i%i", &S,&pizza1n,&pizza2n);
	for (int x = 0; x < pizza1n; x++) {
		scanf("%i", &pizza1[x]);
	}
	for (int x = 0; x < pizza2n; x++) {
		scanf("%i", &pizza2[x]);
	}
	for (int x = 0; x < pizza1n; x++) {
		int sum = 0;
		for (int y = 0; y < pizza1n-1; y++){
			sum += pizza1[(x + y)%pizza1n];
			pizzasum1.push_back(sum);
			if (sum == S) {
				count++;
			}
		}
	}
	for (int x = 0; x < pizza2n; x++) {
		int sum = 0;
		for (int y = 0; y < pizza2n-1; y++) {
				sum += pizza2[(x + y) % pizza2n];
				pizzasum2.push_back(sum);
				if (sum == S) {
					count++;
				}
		}
	}
	int sum = 0;
	for (int x = 0; x < pizza2n; x++) {
		sum += pizza2[x];
	}
	pizzasum2.push_back(sum);
	if (sum == S) {
		count++;
	}
	sum = 0;
	for (int x = 0; x < pizza1n; x++) {
		sum += pizza1[x];
	}
	pizzasum1.push_back(sum);
	if (sum == S) {
		count++;
	}
	sort(pizzasum1.begin(), pizzasum1.end());
	sort(pizzasum2.begin(), pizzasum2.end());
	int left = 0;
	int right = pizzasum2.size() - 1;
	int tempsum = 0;
	while (left <= pizzasum1.size() - 1 && right >= 0) {
		tempsum = pizzasum1[left] + pizzasum2[right];
		if (tempsum <= S) {
			if (tempsum == S) {
				int ncount1 = 1;
				int ncount2 = 1;
				for (int x = left; x < pizzasum1.size() - 1; x++) {
					if (pizzasum1[x] == pizzasum1[x + 1])
					{
						ncount1++;
						left++;
					}
					else {
						break;
					}
				}
				for (int x = right; x >= 1; x--) {
					if (pizzasum2[x] == pizzasum2[x - 1]) {
						ncount2++;
						right=x-1;
					}
					else {
						break;
					}
				}
				count += ncount1 * ncount2;
			}
			left++;
		}
		else {
			right--;
		}
	}
	printf("%i", count);
}