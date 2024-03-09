#include <bits/stdc++.h>
using namespace std;
/*


*/
int t, n;
int S[505], cache[505];
//cache[st] = st에서 시작하는 LIS 의 길이

int lis(int st) {
	int& ret = cache[st+1];
	if (ret != -1) return ret;
	
	ret = 1;
	for (int nxt = st+1; nxt < n; nxt++)
	{
		if (st != -1 && S[st] >= S[nxt]) continue;
		ret = max(ret, lis(nxt) + 1);
	}
	return ret;
}



int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////

	cin >> t;

	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> S[i];
		}
		memset(cache, -1, sizeof(cache));
		int ans = lis(-1);
		ans--;
		cout << ans << '\n';
	}


	/////////////////////////////////////////////////////////////////
	return 0;
}
