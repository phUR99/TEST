#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;
#define ll long long
int d[41][2];
vector<int> v;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	d[0][0] = 1; d[0][1] = 0;
	d[1][1] = 0; d[1][0] = 1;
	d[2][0] = 1; d[2][1] = 1;
	
	int n; cin >> n;
	int m; cin >> m;
	v.push_back(0);
	while (m--)
	{
		int temp; cin >> temp;
		v.push_back(temp);
	}
	v.push_back(n + 1);
	for (int i = 3; i <=n; i++)
	{
			d[i][0] = d[i - 1][0] + d[i - 1][1];
			d[i][1] = d[i - 1][0];
	}

	int ans = 1;
	for (int i = 1; i < v.size(); i++)
	{
		int temp = v[i] - v[i - 1] - 1;
		int sum = d[temp][0] + d[temp][1];
		ans *= sum;
	}
	cout << ans;
}
