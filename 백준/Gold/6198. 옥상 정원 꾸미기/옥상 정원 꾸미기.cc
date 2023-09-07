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
	stack<int> s;
	int temp;
	int n;
	long long int ans = 0;
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		cin >> temp;
		while (!s.empty() && s.top() <= temp) {
			s.pop();
		}
		ans += s.size();
		s.push(temp);

	}
	cout << ans;

}