#include <bits/stdc++.h>
using namespace std;
//idea: 2번을 계속해서 찾으나 3번을 계속해서 찾으나 결국에 답을 찾는다면 동일한 형태가 되는 것에 주목
//한쪽 방향으로 계속 탐색한 후에 덱의 사이즈에서 그 값을 빼준다면 반대방향으로 탐색한 결과를 도출할 수 있다.

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	int n, k, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}
	cin >> k;
	while (k--)
	{
		int t;
		int cnt = 0;
		cin >> t;
		while (dq.front() != t)
		{
			dq.push_back(dq.front());
			dq.pop_front();
			cnt++;
		}
		ans += min(cnt, (int)dq.size() - cnt);
		dq.pop_front();
	}
	cout << ans;

}
