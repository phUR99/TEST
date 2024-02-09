#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int ans = 100005;
	int tmp;
	cin >> n;
	for (int i = 0; 5*i <= n; i++)
	{
		int cur = n;
		tmp = i;
		cur -= 5* i;
		if (cur % 2 == 0) {
			tmp += cur /2;
			ans = min(ans, tmp);
		}		
	}
	if (ans == 100005) {
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}