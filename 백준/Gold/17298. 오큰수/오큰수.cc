#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int ans[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> arr[i];
	}
	for (int i = t-1; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= arr[i]) s.pop();
		if (s.empty()) ans[i] = -1;
		else ans[i] = s.top();
		s.push(arr[i]);
	}
	for (int i = 0; i < t; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}