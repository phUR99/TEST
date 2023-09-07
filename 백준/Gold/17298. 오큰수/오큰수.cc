#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<pair<int,int>> s;
	vector<pair<int, int>> ans;
	int n;
	cin >> n;
	int temp;
	int cnt;
	for (int i = 1; i <= n; i++)
	{
		cnt = 0;
		cin >> temp;
		while (!s.empty() && s.top().first < temp)
		{
			ans.push_back({ s.top().second, temp });
			s.pop();
		}
		s.push({ temp, i });

	}
	while (!s.empty())
	{
		ans.push_back({ s.top().second, -1 });
		s.pop();
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans)
	{
		cout << i.second << " ";
	}
}