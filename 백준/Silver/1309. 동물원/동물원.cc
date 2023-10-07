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
ll d[100'005][3];
int k = 9901;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	d[0][0] = 1;
	for (int i = 1; i <=n; i++)
	{
		d[i][0] = (d[i - 1][1] + d[i - 1][2] +d[i-1][0]) % k;
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) %k;
		d[i][2] = (d[i - 1][0] + d[i - 1][1]) %k;
	}
	cout << (d[n][0] + d[n][1] + d[n][2]) % k;
}
