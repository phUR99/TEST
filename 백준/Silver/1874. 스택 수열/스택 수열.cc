#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	int cnt = 1;
	int n;
	cin >> n;
	string ans = "";
	while (n--)
	{
		int tmp;
		cin >> tmp;
		while (cnt <= tmp)
		{
			s.push(cnt++);
			ans += "+\n";
		}
		if (s.top() != tmp)
		{
			cout << "NO";
			return 0;
		}
		s.pop();
		ans += "-\n";
	}
	cout << ans;
}