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
int a[500'005], b[500'005];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		if (!binary_search(b, b + m, a[i])) ans.push_back(a[i]);
	}
	if (ans.empty()) {
		cout << 0;
		return 0;
	}
	cout << ans.size() << '\n';
	for (auto i : ans)
	{
		cout << i << ' ';
	}
}