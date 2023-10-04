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
int arr[100'001][3];
int d[100'001][3];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i][1];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i][2];
		}
		d[1][1] = arr[1][1];
		d[1][2] = arr[1][2];
		for (int i = 2; i <= n; i++)
		{
			d[i][0] = max({d[i-1][1], d[i-1][2]});
			d[i][1] = max({ d[i - 1][0], d[i - 1][2] }) + arr[i][1];
			d[i][2] = max({ d[i - 1][0], d[i - 1][1] }) + arr[i][2];
		}
		cout << max({ d[n][0], d[n][1], d[n][2] }) << '\n';
	}


}
