#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		stack<char> s;

		for (auto e: str)
		{
			if (s.empty() || s.top() != e) s.push(e);
			else if (!s.empty() && s.top() == e) s.pop();
		}
		if (s.empty()) ans++;
	}
	cout << ans;
}