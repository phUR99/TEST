#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		stack<char> s;
		for (auto i : temp)
		{
			if (s.empty() || s.top() !=i) s.push(i);
			else s.pop();
		}
		if (s.empty()) ans++;
	}
	cout << ans;
}