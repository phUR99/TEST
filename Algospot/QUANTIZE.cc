#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*

*/
int n, s, t;
int arr[105];
int pSum[105], pSquareSum[105];
//i번째 숫자부터 j개의 숫자를 잡았을 때, 그 때의 오차 제곱의 합의 최솟값
int cache[105][105];
// n의 숫자를 s개로 분할하고, 그 때의 오차 제곱의 합의 최솟값을 계산하여 그 합을 반환하는 함수
int minError(int lo, int hi) {
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int squareSum = pSquareSum[hi] - (hi == 0 ? 0 : pSquareSum[lo - 1]);

	int m = int(0.5 + (double)sum / (hi - lo + 1));
	int ret = squareSum - 2 * m * sum + m * m * (hi - lo + 1);
	return ret;
}


int errorSquareSum(int begin, int parts) {
	if (begin == n) return 0;
	// 아직 분할해야 하는 횟수가 남았는데 문자의 길이가 끝났을 때의 처리가 고민이었다.
	// 근데 책에서는 parts의 수를 줄이면서 먼저 begin이 문자의 끝에 도달했는 지를 체크하고, 
	// 그 후에 parts가 0인지를 체크하면서 문자가 남았는데 분할 횟수가 끝난 경우를 
	// MX를 반환함으로 의미없는 값을 통해서 없애버렸다.
	// 이 문제에서 가장 중요한 테크닉!!
	if (parts == 0) return MX;

	int& ret = cache[begin][parts];
	if (ret != -1) return ret;
	ret = MX;

	for (int partSize = 1; begin + partSize <= n; partSize++)
	{
		ret = min(ret, minError(begin, begin + partSize - 1) + errorSquareSum(begin + partSize, parts - 1));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];			
		}

		sort(arr, arr + n);
		for (int i = 0; i < n; i++)
		{
			pSum[i] = (i == 0 ?  arr[i] : pSum[i - 1] + arr[i]);
			pSquareSum[i] = (i == 0 ? arr[i] * arr[i] : pSquareSum[i - 1] + arr[i] * arr[i]);
		}
		memset(cache, -1, sizeof(cache));
		int ans = errorSquareSum(0, s);
		cout << ans << '\n';
	}

	/////////////////////////////////////////////////////////////////
	return 0;
}
