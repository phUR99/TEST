#include <bits/stdc++.h>
using namespace std;
int n, h[100002], ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	stack<int> s;
	// 오류 방지용 0
	s.push(0);
	// n+1을 추가한 이유는 마지막으로 사용한 스택을 비우고 계산하기 위해서
	for (int i = 1; i <= n + 1 ; i++)
	{
		//현재 인덱스의 탑의 높이가 스택의 인덱스의 탑의 높이보다 낮을 경우
		while (!s.empty() && h[s.top()] > h[i]) {			
			//하나씩 빼면서 최댓값을 계산한다.
			int chk = s.top();
			s.pop();
			ans = max(ans, h[chk] * (i - s.top() - 1));
		}
		s.push(i);
	}
	cout << ans;
}
