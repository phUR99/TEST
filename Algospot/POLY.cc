#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*
POLY: 현재의 모양을 결정하는 문제와 그 나머지를 재귀로 구현하는 문제
cache(i, j) : i개의 정사각형으로 이루어져있고, 맨 위 가로줄에 j개의 정사각형을 포함하는 폴리오미노의 수를 반환한다.
맨 윗줄에 몇개의 정사각형을 쓸 지를 결정하고, 그 값만큼을 뺀 부분문제를 재귀적으로 구현한다. 
-> 다만 이런식의 구현은 첫번째 시도에서는 예외적인 구현이 필요하다. (반드시 첫번째 조각이 필요한데, 첫번째 시도에서는 첫번째 조각에 대한 정보가 없다)

*/
const int MOD = 10000000;
int cache[102][102];
int t;
// 정사각형의 수 n 개와 맨 윗줄에서 사용할 정사각형의 개수 first개를 받아서 가능한 폴리오미노의 개수를 반환해주는 함수
int poly(int n, int first) {
	//기저조건 1: 맨 위의 줄을 구성할 수가 현재 가진 정사각형의 개수와 동일하다면 그 경우의 수는 하나밖에 없다.
	if (n == first) return 1;
	//메모이제이션 확인
	int& ret = cache[n][first];
	if (ret != -1) return ret;
	ret = 0;
	// 1~부터 n-first개까지 확인하면서 가능한 경우의 개수를 센다
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
			//첫번째 경우는 예외로 반드시 세어줘야 한다.
			ans += poly(n, i);
			ans %= MOD;
		}
		cout << ans << '\n';
	}
	


	/////////////////////////////////////////////////////////////////
	return 0;
}
