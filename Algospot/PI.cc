#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*

*/
int t;
string N;
int cache[10005];

int classify(int st, int ed) {
  // begin으로부터 ed-st+1개 만큼의 문자 조각을 가져온다
	string M = N.substr(st, ed - st + 1);
  // 전부 한 글자일 때 1 반환
	if (M == string(M.size(), M[0])) return 1;
  // 등차수열일 경우 
	bool progressive = true;
	for (int i = 0; i < M.size()-1; i++)
	{
		if (M[i + 1] - M[i] != M[1] - M[0]) progressive = false;
	}
  //등차수열이면서 그 차가 1이면 2 반환
	if (progressive && abs(M[1] - M[0]) == 1) return 2;

  //교대급수 확인
	bool alternating = true;
	for (int i = 0; i < M.size(); i++)
	{
		if (M[i] != M[i % 2]) alternating = false;
	}

	if (alternating) return 4;
	if (progressive) return 5;
  //아무것도 아니라면
	return 10;
}
// N[begin...] 중 최소의 값 반환
int memorize(int begin) {
	if (begin == N.size()) return 0;

	int& ret = cache[begin];
	if (ret != -1) return ret;

	ret = MX;
	for (int L = 3; L <= 5; L++)
	{
		if (begin + L <= N.size()) ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> t;
	while (t--)
	{
		cin >> N;
		memset(cache, -1, sizeof(cache));
		int ans  = memorize(0);
		cout << ans << '\n';
	}

	/////////////////////////////////////////////////////////////////
	return 0;
}
