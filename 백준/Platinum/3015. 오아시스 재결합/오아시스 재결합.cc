#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//높이와 같은 정보의 등장 횟수를 기록하기 위해서 stack을 pair로 선
	stack<pair<int, int>> s;
	int n;
	cin >> n;
	long long ans = 0;
	while (n--)
	{
		int h;
		// 같은 높이의 등장횟수를 세어줄 변수 cnt 선언. 기본값 1
		int cnt = 1;
		cin >> h;
		// 스택이 작거나 같을 때 계속 while문 수행
		while (!s.empty() && s.top().first <= h)
		{
			ans += s.top().second;
			//같은 정보의 등장 횟수를 더해준다
			if (h == s.top().first) cnt += s.top().second;
			//같으면 cnt에 기존 등장횟수를 더해준다 1 + 기존 등장횟수
			s.pop();
		}
		// 첫번째 쿼리에 더하는 것을 피하기 위해서 empty 조건을 달아준 후에 각 쿼리마다 만나는 것을 더해줌
		if (!s.empty()) ans++;
		// 이후 스택에 추가
		s.push({ h, cnt });
	}
	cout << ans;
}
