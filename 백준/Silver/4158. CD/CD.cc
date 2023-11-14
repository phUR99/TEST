#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	while (true)
	{
		int n, m, temp;
		cin >> n >> m;
		int cnt = 0;
		vector<int> v;
		if (n == 0 && m == 0) return 0;
		while (n--)
		{
			cin >> temp;
			v.push_back(temp);
		}
		while (m--)
		{
			cin >> temp;
			if (binary_search(v.begin(), v.end(), temp)) cnt++;		
		}
		cout << cnt << '\n';

		
	}

}