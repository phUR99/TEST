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
ll d[35][35];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	for (int i = 1; i <= 31; i++) {
		d[1][i] = i;
		for (int j = 2; j <= i; j++) {
			d[j][i] = d[j - 1][i - 1] + d[j][i - 1];

		}
	}
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		cout << d[n][m] << '\n';
	}

}