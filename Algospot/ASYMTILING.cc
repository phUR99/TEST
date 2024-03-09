#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*

*/
int cache[105];
int t, n;
const int MOD = 1000000007;
int tiling(int width) {
	if (width <= 1) return 1;

	int& ret = cache[width];
	if (ret != -1) return ret;

	return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;

}


int asyTiling(int width) {
	if (width % 2 == 1) return (tiling(width) - tiling(width / 2) + MOD) % MOD;

	int ret = tiling(width);
	ret = (ret - tiling(width / 2) + MOD) % MOD;
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
	
	return ret;

}




int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> t;
	memset(cache, -1, sizeof(cache));
	while (t--)
	{

		cin >> n;
		cout << asyTiling(n) << '\n';
	}
	


	/////////////////////////////////////////////////////////////////
	return 0;
}
