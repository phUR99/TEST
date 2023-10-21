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



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> lat, ver;
	int x, y;
	cin >> x >> y;
	lat.push_back(0);lat.push_back(y);
	ver.push_back(0);ver.push_back(x);
	int t;
	cin >> t;
	while (t--)
	{
		int pos, temp;
		cin >> pos >> temp;
		if (pos)
		{
			ver.push_back(temp);
		}
		else
		{
			lat.push_back(temp);
		}
	}
	sort(ver.begin(), ver.end());
	sort(lat.begin(), lat.end());
	int ans = 0;
	for (int i = 1; i < ver.size(); i++)
	{
		for (int j = 1; j < lat.size(); j++) {
			ans = max(ans, (ver[i] - ver[i - 1]) * (lat[j] - lat[j - 1]));
		}
	}
	cout << ans;
}