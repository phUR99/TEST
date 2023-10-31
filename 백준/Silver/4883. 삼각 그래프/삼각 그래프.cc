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
int arr[100005][3];
int d[100005][3];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 1;
	while (true)
	{
		int n; cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		}
		d[1][0] = 1000001; d[1][1] = arr[1][1]; d[1][2] = d[1][1] + arr[1][2];
		for (int i = 2; i <= n; i++)
		{
			d[i][0] = min(d[i - 1][0], d[i - 1][1]) + arr[i][0];
			d[i][1] = min({d[i - 1][0], d[i - 1][1], d[i-1][2], d[i][0]}) + arr[i][1];
			d[i][2] = min({ d[i - 1][1], d[i - 1][2], d[i][1] }) + arr[i][2];
		}
		cout << cnt << ". " << d[n][1] << '\n';
		cnt++;
	}
}