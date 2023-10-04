#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>
using namespace std;
#define ll long long

int d[40];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	d[0] = 1; d[2] = 3;
	for (int i = 3; i <= n; ++i) {
		d[i] += d[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) {
			d[i] += d[j] * 2;
		}
	}
	cout << d[n];
	
}
