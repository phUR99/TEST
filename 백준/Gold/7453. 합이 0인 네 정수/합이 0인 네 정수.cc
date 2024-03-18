#include <bits/stdc++.h>
using namespace std;

// 4중 for문 -> o(4000^4) x
// a+b 와 c+d를 비교하기 2*n^2 * 2logn _> n^2logN
int a[4004], b[4004], c[4004], d[4004];

int main() {
    ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	vector<int> ab, cd;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}
	long long p1 = 0, p2 = 0;
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end(), greater<>());
	long long ans = 0;
	while (p1 < ab.size() && p2 <cd.size())
	{
		if (ab[p1] + cd[p2] < 0) {
			p1++;
		}
		else if (ab[p1] + cd[p2] == 0) {
			long long t1 = p1, t2 = p2;
			while (p1 < ab.size() && ab[p1] == ab[t1])
			{				
				p1++;
			}
			while (p2 < cd.size() && cd[p2] == cd[t2])
			{				
				p2++;
			}
			ans += (p1 - t1) * (p2-t2);
		}
		else
		{
			p2++;
		}
	}
	cout << ans;
}