#include <bits/stdc++.h>
using namespace std;
int n, h[100002], ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	stack<int> s;
	s.push(0);
	for (int i = 1; i <= n + 1 ; i++)
	{
		while (!s.empty() && h[s.top()] > h[i]) {
			int chk = s.top();
			s.pop();
			ans = max(ans, h[chk] * (i - s.top() - 1));
		}
		s.push(i);
	}
	cout << ans;
}