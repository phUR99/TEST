#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	int n;
	cin >> n;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 0) s.pop();
		else s.push(tmp);
	}
	int ans = 0;
	while (!s.empty())
	{
		ans += s.top();
		s.pop();
	}
	cout << ans;
	return 0;
}