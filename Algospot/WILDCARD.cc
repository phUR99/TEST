#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*

*/
int t;

int cache[101][101];
string W, S;
// string W와 S의 match 여부를 반환하는 함수 (메모이제이션 활용)
bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];
  //기저조건 1 : 메모이제이션이 활용되었다면 그 값을 반환
	if (ret != -1) return ret;
  //match 될 때는 현재 값을 체크하고 다음으로 넘겨줌
	if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
	{
		return ret = matchMemoized(w+1, s+1);
	}
  // W의 끝까지 왔을 경우 S의 끝까지 왔는지를 확인하고 반환
	if (w == W.size()) return ret = (s == S.size());
  // W의 현재 값이 *일 경우 한칸씩 진행하면서 매치가 되는지를 확인함.
	if (W[w] == '*') {
		if (matchMemoized(w + 1, s) || (s < S.size() && matchMemoized(w, s + 1))) return ret = 1;
	}
  //이에 해당되지 않을 경우 매칭되지 않는다.
	return ret = 0;
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////

	cin >> t;
	while (t--)
	{		
		cin >> W;
		int n;
		cin >> n;
		vector<string> ans;

		while (n--)
		{
			cin >> S;
			memset(cache, -1, sizeof(cache));
			if (matchMemoized(0, 0)) ans.push_back(S);
		}
		sort(ans.begin(), ans.end());
		for (auto node : ans)
		{
			cout << node << '\n';
		}
	}

	/////////////////////////////////////////////////////////////////
	return 0;
}
