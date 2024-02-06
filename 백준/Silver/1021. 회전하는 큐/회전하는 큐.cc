#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	int n, k, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}
	cin >> k;
	while (k--)
	{
		int t;
		int cnt = 0;
		cin >> t;
		while (dq.front() != t)
		{
			dq.push_back(dq.front());
			dq.pop_front();
			cnt++;
		}
		ans += min(cnt, (int)dq.size() - cnt);
		dq.pop_front();
	}
	cout << ans;

}