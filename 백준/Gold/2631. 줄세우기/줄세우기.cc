#include <bits/stdc++.h>
using namespace std;
/*


*/

int n;
int cache[205], arr[205];
int lis(int st) {
	int& ret = cache[st + 1];
	if (ret != -1) return ret;

	ret = 1;
	for (int nxt = st+1; nxt < n; nxt++)
	{
		if (st == -1 || arr[st] < arr[nxt]) ret = max(ret, lis(nxt) + 1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////

	cin >> n;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << n - lis(-1) + 1;
	/////////////////////////////////////////////////////////////////
	return 0;
}