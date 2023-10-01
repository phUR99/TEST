#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, temp;
	int n, m, ans;
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> m;
		vector<int> a, b;
		for (int i = 0; i < n; i++)
		
		{
			cin >> temp;
			a.push_back(temp);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> temp;
			b.push_back(temp);
		}
		sort(a.begin(), a.end(), greater<>());
		sort(b.begin(), b.end(), greater<>());
		
		int cnt = 0;

		for (int i = 0; i < n ; i++)
		{
			
			if (a[i] <= b[cnt]) {
				while (cnt < m && a[i] <= b[cnt])
				{
					cnt++;
				}
			}
			if (cnt == m) break;
			else
			{
				ans += m-cnt;
			}
		}
		cout << ans << '\n';
	}
}
