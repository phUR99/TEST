#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		stack<pair<long long, long long>> s;
		long long ans = 0;
		//1. 블럭을 스택에 넣어주면서 max값을 찾기
		for (int i = 0; i < n; i++)
		{
			int h;
			cin >> h;
			int idx = i;
			//입력된 h가 현재 스택의 탑보다 작거나 같을 때
			//스택은 항상 오름차순으로(가장 최근에 들어온 값이 크다)
			while (!s.empty() && s.top().first >= h)
			{
				//현재 스택의 인덱스에서 tmp의 인덱스를 뺀 값(가로) * 스택의 높이(세로)를 계산한 최댓값
				ans = max(ans, (i - s.top().second) * s.top().first);
				idx = s.top().second;
				s.pop(); // 제거
			}
			s.push({ h, idx });

		}
		//이후 스택을 거꾸로 탐색하면서 최댓값 찾기
		while (!s.empty())
		{
			ans = max(ans, (n - s.top().second) * s.top().first);
			s.pop();

		}
		cout << ans << '\n';
	}

}