#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<pair<int, int>> s;
	int n;
	cin >> n;
	long long ans = 0;
	while (n--)
	{
		int h;
		int cnt = 1;
		cin >> h;
		while (!s.empty() && s.top().first <= h)
		{
			ans += s.top().second;
			if (h == s.top().first) cnt += s.top().second;
			s.pop();
		}
		if (!s.empty()) ans++;
		s.push({ h, cnt });
	}
	cout << ans;
}