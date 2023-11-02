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
string arr[105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	for (size_t i = 0; i < m; i++)
	{
		vector<int> v1, v2;
		int temp;
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			v1.push_back(temp);
			v2.push_back(temp);
		}
		sort(v2.begin(), v2.end());
		v2.erase(unique(v2.begin(), v2.end()), v2.end());
		for (int j = 0; j < n; j++)
		{
			int t = lower_bound(v2.begin(), v2.end(), v1[j]) - v2.begin();
			arr[i] += to_string(t);
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++) {
			if (arr[i] == arr[j]) ans++;
		}
	}
	cout << ans;
}