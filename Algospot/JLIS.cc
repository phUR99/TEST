#include <bits/stdc++.h>
using namespace std;
/*


*/
int t, n, m;
const long long MX = -1e15;

int A[505], cache[505][505], B[505];
//cache[Ast][Bst]
//aidx, bidx 에서 시작한 JLIS의 길이를 반환한다.
int lis(int aIdx, int bIdx) {
	int& ret = cache[aIdx +1][bIdx+1];
	if (ret != -1) return ret;
	
	ret = 0;
	long long a = (aIdx == -1) ? MX : A[aIdx];
	long long b = (bIdx == -1) ? MX : B[bIdx];
	long long maxElement = max(a, b); 

	for (int nxt = aIdx+1; nxt < n; nxt++)
	{
		if (maxElement < A[nxt]) ret = max(ret, lis(nxt, bIdx) + 1);
	}
	for (int nxt = bIdx +1; nxt < m; nxt++)
	{
		if (maxElement < B[nxt]) ret = max(ret, lis(aIdx, nxt) + 1);
	}
	return ret;
}



int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////

	cin >> t;

	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> B[i];
		}
		memset(cache, -1, sizeof(cache));
		int ans = lis(-1, -1);

		cout << ans << '\n';
	}


	/////////////////////////////////////////////////////////////////
	return 0;
  
}
