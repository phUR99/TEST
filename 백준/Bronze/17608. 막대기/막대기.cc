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
		int h;
		cin >> h;
		while (!s.empty() && s.top() <= h)
		{
			s.pop();
		}
		s.push(h);
	}
	cout << s.size();

}