#include <bits/stdc++.h>
using namespace std;
bool chk[2000005];
int arr[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		if (x - arr[i] > 0 && chk[x - arr[i]]) ans++;
		chk[arr[i]] = true;
	}
	cout << ans;
}