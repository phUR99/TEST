#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*
POLY: 현재의 모양을 결정하는 문제와 그 나머지를 재귀로 구현하는 문제
cache(i, j) : i개의 정사각형으로 이루어져있고, 맨 위 가로줄에 j개의 정사각형을 포함하는 폴리오미노의 수를 반환한다.


*/
const int MOD = 10000000;
int cache[102][102];
int t;

int poly(int n, int first) {
	if (n == first) return 1;

	int& ret = cache[n][first];
	if (ret != -1) return ret;
	ret = 0;
	for (int second = 1; second <= n - first; second++)
	{
		int add = second + first - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}



int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> t;
	memset(cache, -1, sizeof(cache));
	while (t--)
	{
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += poly(n, i);
			ans %= MOD;
		}
		cout << ans << '\n';
	}
	


	/////////////////////////////////////////////////////////////////
	return 0;
}
