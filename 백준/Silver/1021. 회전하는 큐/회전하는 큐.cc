#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> D, S;
	int n, m, idx, cnt;
	int ans = 0;
	cin >> n >> m;
	
	for ( int i = 1; i <= n; i++)
	{
		D.push_back(i);
	}
	for (int i = 1; i <= m; i++)
	{
		int temp;
		cin >> temp;
		S.push_back(temp);
	}
	while (!S.empty())
	{
		cnt = 0;
		for (int i = 0; i < D.size(); i++) {
			if (D[i] == S.front()) idx = i;
		}
		if (idx > D.size() /2)
		{
			while (S.front() != D.front()) {
				D.push_front(D.back());
				D.pop_back();
				cnt++;
			}
			D.pop_front();
			S.pop_front();
		}
		else 
		{
			while (S.front() != D.front())
			{
				D.push_back(D.front());
				D.pop_front();
				cnt++;
			}
			D.pop_front();
			S.pop_front();
		}
		ans += cnt;
	}
	
	cout << ans;
}