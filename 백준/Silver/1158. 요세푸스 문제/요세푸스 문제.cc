#include <bits/stdc++.h>
using namespace std;

int arr[5005];
int nxt[5005];
int pre[5005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
		nxt[i] = i + 1;
		pre[i] = i - 1;
		if (i == n) nxt[i] = 1;
		if (i == 1) pre[i] = n;
	}
	int t = 1;
	if (n == 1) {
		cout << "<1>";
		return 0;
	}
	vector<int> ans;

	while (true)
	{
		if (ans.size() == n) break;

		for (int i = 1; i <= k; i++)
		{			
			if (i == k) {
				ans.push_back(arr[t]);
				nxt[pre[t]] = nxt[t];
				pre[nxt[t]] = pre[t];
			}
			t = nxt[t];
		}
	}
	cout << "<";
	for (int i = 0; i < n; i++)
	{
		cout << ans[i];
		if (i != n - 1) cout << ", ";
		else cout << ">";
	}
	return 0;
}