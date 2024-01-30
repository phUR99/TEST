#include <bits/stdc++.h>
using namespace std;
#define MAX 100'000'001 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<pair<int, int>> s;
	int cnt = 0;
	s.push(make_pair(MAX, cnt));
	int t;
	cin >> t;
	
	while (t--)
	{
		int t_h;
		cin >> t_h;
		while (s.top().first < t_h)
		{
			s.pop();
		}		
		cout << s.top().second << ' ';
		s.push({ t_h, ++cnt });
		
		
	}
	return 0;
}