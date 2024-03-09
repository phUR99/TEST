#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*

*/
int cache[105];
int t;

int tiling(int cur) {
	if (cur <= 1) return 1;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	return ret = (tiling(cur - 1) + tiling(cur - 2)) %1000000007;
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	memset(cache, -1, sizeof(cache));

	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << tiling(n) << '\n';
	}

	/////////////////////////////////////////////////////////////////
	return 0;
}
